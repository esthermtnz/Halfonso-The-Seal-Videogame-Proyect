/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "game_management.h"

/**
 * @brief Structure that contains all the info needed to run the game
 */
struct _Game
{
  Player *player;                      /*!< Pointer to player */
  Object *object[MAX_OBJ];             /*!< Pointer to object */
  Space *spaces[MAX_SPACES];           /*!< Pointer to space */
  Link *link[MAX_LINKS];               /*!< Pointer to links */
  T_Command last_cmd;                  /*!< Last command */
  Enemy *enemy;                        /*!< Pointer to enemy */
  STATUS lcstatus;                     /*!< Last command status */
  char description[WORD_SIZE + 1];     /*!< Description for command inspect */
  char illudescription[WORD_SIZE + 1]; /*!< Description for the illumination of a space*/
};
/**
   Private functions
*/

/**
 * @brief Gets the space id at "i"
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @param position space position
 * @return returns an id
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief Obtains an object by its id
 * @author Jaime Sánchez Esteban
 *
 * @param game a pointer to the game
 * @param id id of the object
 * @return returns the object or NULL in case of error
 */
Object* game_get_object_by_id(Game *game, Id id);

/**
 * @brief Obtains the objects id from the player inventory by the name
 * @author Jaime Sánchez Esteban
 *
 * @param game a pointer to the game
 * @param name name of the object
 * @return returns the object id
 */
Id game_get_player_object_by_name(Game *game, char *name);

/**
 * @brief loads the enemy
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @param filename enemy's filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_enemy(Game *game, char *filename);

/**
 * @brief loads the player
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @param filename player's filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_player(Game *game, char *filename);

/**
 * @brief unknown command
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_unknown(Game *game);
/**
 * @brief exit command
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_exit(Game *game);

/**
 * @brief move command
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_move(Game *game);
/**
 * @brief take command
 * @author Jaime Sánchez Esteban
 *
 * @param game a pointer to the game
 */
void game_command_take(Game *game);
/**
 * @brief drop command
 * @author Jaime Sánchez Esteban
 *
 * @param game a pointer to the game
 */
void game_command_drop(Game *game);
/**
 * @brief turnon command
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 */
void game_command_turnon(Game *game);
/**
 * @brief turnoff command
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 */
void game_command_turnoff(Game *game);
/**
 * @brief attack command
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_attack(Game *game);
/**
 * @brief inspect command
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_inspect(Game *game);
/**
 * @brief opens links with objects
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_open(Game *game);

/**
 * @brief Saves the game
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_save(Game *game);
/**
 * @brief Loads the game
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 */
void game_command_load(Game *game);
/**
   Game interface implementation
*/

Game *game_create()
{
  Game *aux = NULL;
  int i;
  aux = (Game *)malloc(sizeof(Game));
  if (aux == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES; i++)
  {
    aux->spaces[i] = NULL;
  }
  srand(time(NULL));

  for (i = 0; i < MAX_OBJ; i++)
  {
    aux->object[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++)
  {
    aux->link[i] = NULL;
  }

  aux->player = NULL;
  aux->enemy = NULL;
  aux->last_cmd = NO_CMD;
  aux->lcstatus = ERROR;
  aux->description[0] = '\0';
  aux->illudescription[0] = '\0';

  return aux;
}

/* Implements a game inferface from a file */
STATUS game_create_from_file(Game *game, char *filename)
{
  if (game == NULL)
  {
    return ERROR;
  }

  if (game_management_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_objects(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_links(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_player(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_enemy(game, filename) == ERROR)
    return ERROR;

  return OK;
}

/* Destroys every space */

STATUS game_destroy(Game *game)
{
  int i = 0;
  if (game == NULL)
  {
    return ERROR;
  }

  player_destroy(game->player);
  enemy_destroy(game->enemy);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < MAX_OBJ && game->object[i] != NULL; i++)
  {
    object_destroy(game->object[i]);
  }

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    link_destroy(game->link[i]);
  }

  free(game);
  game = NULL;

  return OK;
}

/* Gets the position of the space where you are */

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/* Checks if the space id got is correct */

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Object *game_get_object(Game *game, int pos)
{

  if (pos < 0 || !game || pos > MAX_OBJ)
  {
    return NULL;
  }
  return game->object[pos];
}

Object* game_get_object_by_id(Game *game, Id id)
{
	int i = 0;
	if (game == NULL || id == NO_ID)
	{
		return NULL;
	}
	else
	{
		for (i = 0; i < MAX_OBJ; i++)
		{
			if (object_get_id(game_get_object(game, i)) == id)
			{
				return game_get_object(game, i);
			}
		}
	}
	return NULL;
}

Player *game_get_player(Game *game)
{
  if (!game)
  {
    return NULL;
  }
  return game->player;
}

Enemy *game_get_enemy(Game *game)
{
  if (!game)
  {
    return NULL;
  }
  return game->enemy;
}

/* Locates the player in the space where he is */

STATUS game_set_player_location(Game *game, Id id)
{
  if (game == NULL)
  {
    return ERROR;
  }

  if (id == NO_ID)
  {
    return ERROR;
  }

  return player_set_location(game->player, id);
}

/* Returns the location of the player */

Id game_get_player_location(Game *game)
{

  return player_get_location(game->player);
}

/*Returns the location of the enemy*/

Id game_get_enemy_location(Game *game)
{
  return enemy_get_location(game->enemy);
}

/*It sets the enemy location*/

STATUS game_set_enemy_location(Game *game, Id id)
{
  if (game == NULL || id == NO_ID)
  {
    return ERROR;
  }

  return enemy_set_location(game->enemy, id);
}

/* Locates the object in the stablished id */

STATUS game_set_object_location(Game *game, Id id_space, Id id_object)
{
  Space *espacio;
  if (game == NULL)
  {
    return ERROR;
  }

  if (id_space == NO_ID)
  {
    return ERROR;
  }

  espacio = game_get_space(game, id_space);

  return space_add_object(espacio, id_object);
}

/* Returns the location of the object */

Id game_get_object_location(Game *game, Id id_object)
{
  int i;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_find_object(game->spaces[i], id_object) == TRUE)
    {
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}
/* Returns the status of the actual space*/
LINKST game_get_connection_status(Game *game, Id origin, DIRECTION dir)
{
  int i;

  if (!game)
  {
    return CLOSE;
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    if (link_get_direction(game->link[i]) == dir && link_get_origin(game->link[i]) == origin)
    {
      return link_get_status(game->link[i]);
    }
  }
  return CLOSE;
}
/* Returns the space of the next space*/
Id game_get_connection(Game *game, Id origin, DIRECTION dir)
{
  int i;
  if (!game)
  {
    return NO_ID;
  }

  for (i = 0; i < MAX_LINKS; i++)
  {
    if (link_get_origin(game->link[i]) == origin && link_get_direction(game->link[i]) == dir)
    {
      return link_get_destination(game->link[i]);
    }
  }
  return NO_ID;
}

/*It gets the illumination of the space*/
BOOL game_get_illumination_of_space(Game *game, Id id)
{
  int i;
  if (!game || !id)
  {
    return FALSE;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return space_get_illumination(game->spaces[i]);
    }
  }
  return FALSE;
}

/*It sets the illumination of the space*/
STATUS game_set_illumination_of_space(Game *game, Space *space, BOOL illumination)
{
  if (!game || !space)
  {
    return ERROR;
  }
  space_set_illumination(space,illumination);
  return OK;
}


BOOL game_get_isthere_object(Game *game,Id id){
  if (!game || id == NO_ID)
  {
    return ERROR;
  }

  return player_isthere_object(game->player,id);
}

/*It sets the health of the enemy*/

STATUS game_set_enemy_health(Game *game, int i)
{
  if (game == NULL)
  {
    return ERROR;
  }

  return enemy_set_health(game->enemy, i);
}
/*It gets the health of the enemy*/
int game_get_enemy_health(Game *game)
{
  if (game == NULL)
  {
    return -1;
  }
  return enemy_get_health(game->enemy);
}

/*It gets if an object is turned on*/
BOOL game_get_turned_of_object(Game *game, Object *object){
   if (!game || !object)
  {
    return FALSE;
  }
  return object_get_turnedon(object);
}

/*It sets if the turned on of an object*/
STATUS game_set_turned_of_object(Game *game, Object *object, BOOL value){
   if (!game || !object)
  {
    return ERROR;
  }
  return object_set_turnedon(object,value);
}

/*It gets if an object can illuminate*/
BOOL game_get_illuminate_of_object(Game *game, Object *object){
   if (!game || !object)
  {
    return FALSE;
  }
  return object_get_illuminate(object);
}

/*It sets if an object can illuminate*/
STATUS game_set_illuminate_of_object(Game *game, Object *object, BOOL value){
   if (!game || !object)
  {
    return ERROR;
  }
  return object_set_illuminate(object,value);
}

/*It checks if the inventory is empty*/
BOOL game_check_if_inventory_isEmpty(Game *game, Player *player){
  if (!game || !player)
  {
    return FALSE;
  }
  return player_inventory_is_empty(player);
}

/*It sets the health of the player*/
STATUS game_set_player_health(Game *game, int i)
{
  if (game == NULL)
  {
    return ERROR;
  }
  return player_set_health(game->player, i);
}

int game_get_player_health(Game *game)
{
  if (game == NULL)
  {
    return ERROR;
  }
  return player_get_health(game->player);
}

/* Updates the state of the game and switches between functions */

STATUS game_update(Game *game, T_Command cmd)
{
  if (game == NULL)
  {
    return ERROR;
  }
  game->last_cmd = cmd;

  switch (cmd)
  {
  case UNKNOWN:
    game_command_unknown(game);
    break;

  case EXIT:
    game_command_exit(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  case MOVE:
    game_command_move(game);
    break;

  case ATTACK:
    game_command_attack(game);
    break;

  case TURNON:
    game_command_turnon(game);
    break;
    
  case TURNOFF:
    game_command_turnoff(game);
    break;
  
  case OPENLINK:
    game_command_open(game);
    break;
  case INSPECT:
    game_command_inspect(game);
    break;
  case SAVE:
    game_command_save(game);
    break;
  case LOAD:
    game_command_load(game);
    break;
  default:
    break;
  }

  return OK;
}
/*Gets the last command introduced */

T_Command game_get_last_command(Game *game)
{

  return game->last_cmd;
}

/* Shows information about the game */

void game_print_data(Game *game)
{

  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }
  player_print(game->player);
  printf("=> Object: \n");
  for (i = 0; i < MAX_OBJ && game->object[i] != NULL; i++)
  {
    object_print(game->object[i]);
  }
}

BOOL game_is_over(Game *game)
{
  if (player_get_health(game->player) <= 0)
  {
    game_set_player_health(game, 0);
    return TRUE;
  }
  if (enemy_get_health(game->enemy) <= 0)
  {
    game_set_enemy_health(game, 0);
    return TRUE;
  }
  return FALSE;
}

/**
   Calls implementation for each action
*/
void game_command_unknown(Game *game)
{
}

/*Exits the implementation and the game stops running*/
void game_command_exit(Game *game)
{
}

/*Gets the status of the last command*/
STATUS game_get_last_command_status(Game *game)
{
  if (game == NULL)
  {
    return ERROR;
  }
  return game->lcstatus;
}

/*Sets the status of the last command*/
STATUS game_set_last_command_status(Game *game, STATUS status)
{
  if (game == NULL)
  {
    return ERROR;
  }
  game->lcstatus = status;
  return OK;
}

/*Gets the description*/
const char *game_get_description(Game *game)
{
  if (game == NULL)
  {
    return ERROR;
  }
  return game->description;
}

/*Sets the description*/
STATUS game_set_description(Game *game, const char *description)
{
  if (game == NULL || !description)
  {
    return ERROR;
  }
  if (!strcpy(game->description, description))
  {
    return ERROR;
  }
  return OK;
}

/*Gets the description of the illumination */
const char *game_get_illudescription(Game *game)
{
  if (game == NULL)
  {
    return ERROR;
  }
  return game->illudescription;
}

/*Sets the description of the illumination*/
STATUS game_set_illudescription(Game *game, const char *illudescription)
{
  if (game == NULL || !illudescription)
  {
    return ERROR;
  }
  if (!strcpy(game->illudescription, illudescription))
  {
    return ERROR;
  }
  return OK;
}

Space *game_get_space_at(Game *game, int i)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->spaces[i];
}

STATUS game_set_space_at(Game *game, int i, Space *space)
{
  if (game == NULL || space == NULL)
  {
    return ERROR;
  }
  game->spaces[i] = space;
  return OK;
}

Object *game_get_object_at(Game *game, int i)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->object[i];
}

STATUS game_set_object_at(Game *game, int i, Object *object)
{
  if (game == NULL || object == NULL)
  {
    return ERROR;
  }
  game->object[i] = object;
  return OK;
}

Link *game_get_link_at(Game *game, int i)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->link[i];
}

STATUS game_set_link_at(Game *game, int i, Link *link)
{
  if (game == NULL || link == NULL)
  {
    return ERROR;
  }
  game->link[i] = link;
  return OK;
}

STATUS game_set_enemy(Game *game, Enemy *enemy)
{
  if (game == NULL || enemy == NULL)
  {
    return ERROR;
  }
  game->enemy = enemy;
  return OK;
}

STATUS game_set_player(Game *game, Player *player)
{
  if (game == NULL || player == NULL)
  {
    return ERROR;
  }
  game->player = player;
  return OK;
}

int game_get_number_objects(Game *game){
  int i = 0;

  if (!game){
    return -1;
  }

  for(i=0;i < MAX_OBJ && game->object[i] != NULL;){
    i++;
  }
  return i;
}

int game_get_number_links(Game *game){
  int i = 0;

  if (!game){
    return -1;
  }

  for(i=0;i < MAX_LINKS && game->link[i] != NULL;){
    i++;
  }
  return i;
}

int game_get_number_spaces(Game *game){
  int i = 0;

  if (!game){
    return -1;
  }

  for(i=0;i < MAX_SPACES && game->spaces[i] != NULL;){
    i++;
  }
  return i;
}


Id game_get_object_by_name(Game *game, char *name)
{
  int i = 0;
  if (game == NULL || name == NULL)
  {
    return NO_ID;
  }
  for (i = 0; i < MAX_OBJ; i++)
  {
    if (strcmp(name, object_get_name(game_get_object_at(game, i))) == 0)
    {
      return object_get_id(game_get_object_at(game, i));
    }
  }
  return NO_ID;
}

Id game_get_player_object_by_name(Game *game, char *name)
{
  int i = 0;
  if (game == NULL || name == NULL)
  {
    return NO_ID;
  }
  for (i = 0; i < player_get_max_inv(game->player); i++)
  {
    if (strcmp(name, object_get_name(game_get_object_at(game, i))) == 0)
    {
      if (player_isthere_object(game->player, object_get_id(game_get_object_at(game, i))) == TRUE)
      {
        return object_get_id(game_get_object_at(game, i));
      }
    }
  }
  return NO_ID;
}

const char *game_get_player_object_name_by_id(Game *game, Id id)
{
  int i = 0;
  if (game == NULL || id == NO_ID || player_inventory_is_empty(game->player) == TRUE)
  {
    return NULL;
  }
  if (player_isthere_object(game->player, id) == TRUE)
  {
    for (i = 0; i < MAX_OBJ; i++)
    {
      if (id == object_get_id(game_get_object_at(game, i)))
      {
        return object_get_name(game_get_object_at(game, i));
      }
    }
  }
  return NULL;
}

/*
 * COMMANDS:
 */

/* Moves the player*/
void game_command_move(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id playerloc_id = NO_ID;
  Id nextpos_id = NO_ID;
  char command[WORD_SIZE];
  DIRECTION dir = N;

  scanf(" %s", command);

  playerloc_id = game_get_player_location(game);
  if (playerloc_id == NO_ID)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == playerloc_id)
    {

      if (strcmp(command, "south") == 0 || strcmp(command, "s") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, S);
        dir = S;
      }
      else if (strcmp(command, "north") == 0 || strcmp(command, "n") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, N);
        dir = N;
      }
      else if (strcmp(command, "east") == 0 || strcmp(command, "e") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, E);
        dir = E;
      }
      else if (strcmp(command, "west") == 0 || strcmp(command, "w") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, W);
        dir = W;
      }

	else if (strcmp(command, "up") == 0 || strcmp(command, "u") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, U);
        dir = U;
      }

      else if (strcmp(command, "down") == 0 || strcmp(command, "d") == 0)
      {
        nextpos_id = game_get_connection(game, current_id, D);
        dir = D;
      }
	
      else
      {
        nextpos_id = NO_ID;
      }

      if (nextpos_id != NO_ID && game_get_connection_status(game, playerloc_id, dir) == OPEN)
      {
        game_set_player_location(game, nextpos_id);
        game_set_description(game, space_get_description(game_get_space(game, nextpos_id)));
        game_set_illudescription(game, " ");
        game_set_last_command_status(game, OK);

        return;
      }
      else
      {
        game_set_last_command_status(game, ERROR);
      }
    }
  }
  return;
}

/*The player takes the object from the space */

void game_command_take(Game *game)
{
  Id objectloc_id = NO_ID;
  Id playerloc_id = NO_ID;
  Id id_object = NO_ID;
  char item_name[WORD_SIZE +1];

  scanf(" %s", item_name);

  id_object = game_get_object_by_name(game, item_name);
  playerloc_id = game_get_player_location(game);
  objectloc_id = game_get_object_location(game, id_object);
  if ((playerloc_id == NO_ID) || (objectloc_id == NO_ID) || (player_inventory_is_full(game->player) == TRUE))
  {
    game_set_last_command_status(game, ERROR);
    return;
  }
  if (object_get_movable(game_get_object_by_id(game, id_object)) == FALSE)
  {
  	game_set_last_command_status(game, ERROR);
  	return;
  }
  if (objectloc_id == playerloc_id)
  {
    player_add_object(game->player, id_object);
    space_del_object(game_get_space(game, objectloc_id), id_object);
    game_set_last_command_status(game, OK);
  }
  else
  {
    game_set_last_command_status(game, ERROR);
  }

  return;
}
/*The player drops the object on the space */

void game_command_drop(Game *game)
{

  Id playerloc_id = NO_ID;
  Id object_id = NO_ID;
  char item_name[WORD_SIZE +1];
  scanf(" %s", item_name);
  
  playerloc_id = game_get_player_location(game);
  object_id = game_get_player_object_by_name(game, item_name);

  if ((playerloc_id == NO_ID) || (object_id == NO_ID) || (player_inventory_is_empty(game->player) == TRUE))
  {
    game_set_last_command_status(game, ERROR);
    return;
  }
  else
  {
    if (player_isthere_object(game->player, object_id) == TRUE)
    {
      game_set_object_location(game, playerloc_id, object_id);
      player_delete_object(game->player, object_id);
      game_set_last_command_status(game, OK);
      return;
    }
    else
    {
      game_set_last_command_status(game, ERROR);
      return;
    }
  }

  return;
}


/*The player attacks an enemy */

void game_command_attack(Game *game)
{
  int numero;
  numero = (rand() % MAX_RAND);
  if (game == NULL)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  if (game_get_enemy_location(game) == game_get_player_location(game))
  {
    if (numero <= 4)
    {
      if ((game_get_enemy_health(game) != 0) && (game_get_player_health(game) != 0))
      {
        game_set_enemy_health(game, game_get_enemy_health(game) - 1);
        game_set_last_command_status(game, OK);
      }
    }
    if (numero >= 5)
    {
      if ((game_get_enemy_health(game) != 0) && (game_get_player_health(game) != 0))
      {
        game_set_player_health(game, game_get_player_health(game) - 1);
        game_set_last_command_status(game, OK);
      }
    }
    if ((game_get_enemy_health(game) == 0) || (game_get_player_health(game) == 0))
    {
      game_set_last_command_status(game, ERROR);
    }
  }
  return;
}
/*Turns On an object*/
void game_command_turnon(Game *game)
{
	Id object_id = NO_ID;
	char item_name[WORD_SIZE +1];
  	scanf(" %s", item_name);
  	object_id = game_get_player_object_by_name(game, item_name);
  	if (object_id == NO_ID || (player_inventory_is_empty(game->player) == TRUE))
  	{
  		game_set_last_command_status(game, ERROR);
  		return;
  	}
  	else
  	{
  		if (player_isthere_object(game->player, object_id) == TRUE)
  		{
  			if (object_get_illuminate(game_get_object_by_id(game, object_id)) == TRUE)
  			{
  				if (object_get_turnedon(game_get_object_by_id(game, object_id)) == TRUE)
  				{
  					game_set_last_command_status(game, ERROR);
  					return;
  				}
  				if (object_set_turnedon(game_get_object_by_id(game, object_id), TRUE) == OK)
  				{
  					game_set_last_command_status(game, OK);
  					return;
  				}
  			}
  		}
  	}
  	game_set_last_command_status(game, ERROR);
  	return;
}

/*Turns Off an object*/
void game_command_turnoff(Game *game)
{
	Id object_id = NO_ID;
	char item_name[WORD_SIZE +1];
  	scanf(" %s", item_name);
  	object_id = game_get_player_object_by_name(game, item_name);
  	if (object_id == NO_ID || (player_inventory_is_empty(game->player) == TRUE))
  	{
  		game_set_last_command_status(game, ERROR);
  		return;
  	}
  	else
  	{
  		if (player_isthere_object(game->player, object_id) == TRUE)
  		{
  			if (object_get_illuminate(game_get_object_by_id(game, object_id)) == TRUE)
  			{
  				if (object_get_turnedon(game_get_object_by_id(game, object_id)) == FALSE)
  				{
  					game_set_last_command_status(game, ERROR);
  					return;
  				}
  				if (object_set_turnedon(game_get_object_by_id(game, object_id), FALSE) == OK)
  				{
  					game_set_last_command_status(game, OK);
  					return;
  				}
  			}
  		}
  	}
  	game_set_last_command_status(game, ERROR);
  	return;
}

/*Inspects the objects and the space*/
void game_command_inspect(Game *game)
{
  int i = 0;
  Id playerloc_id = NO_ID;
  char toinsp_obj[WORD_SIZE + 1];
  Object *obj_tofind;
  Space *actual_space;

  scanf(" %s", toinsp_obj);

  playerloc_id = game_get_player_location(game);
  actual_space = game_get_space(game, playerloc_id);

  if (playerloc_id == NO_ID || !game)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJ && game->object[i] != NULL; i++)
  {
    if (strcmp(object_get_name(game->object[i]), toinsp_obj) == 0)
    {
      obj_tofind = game->object[i];
    }
  }

  if (strcmp(toinsp_obj, "Space") == 0 || strcmp(toinsp_obj, "space") == 0 || strcmp(toinsp_obj, "s") == 0)
  {
    game_set_illudescription(game, space_get_illudescription(actual_space));
    game_set_last_command_status(game, OK);
    return;
  }
  else
  {
    if (space_get_illumination(actual_space) == TRUE)
    {
      if (toinsp_obj == NULL || game_get_object_location(game, object_get_id(obj_tofind)) == NO_ID)
      {
        game_set_last_command_status(game, ERROR);
      }

      if (player_isthere_object(game->player, object_get_id(obj_tofind)) == TRUE || space_find_object(actual_space, object_get_id(obj_tofind)) == TRUE)
      {
        game_set_illudescription(game, object_get_description(obj_tofind));
        game_set_last_command_status(game, OK);
      }
      else
      {
        game_set_last_command_status(game, ERROR);
        return;
      }
    } else {
    game_set_last_command_status(game, ERROR);
    }
  }
  return;
}

/*Opens the links using an object*/
void game_command_open(Game *game)
{
  Id playerloc_id = NO_ID;
  char linkname[WORD_SIZE + 1];
  char objname[WORD_SIZE + 1];
  Link *link = NULL;
  Object *object = NULL;
  int i = 0;

  scanf(" %s with %s", linkname, objname);
  playerloc_id = game_get_player_location(game);
 

  if (playerloc_id == NO_ID || !game)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++)
  {
    if (strcmp(link_get_name(game->link[i]), linkname) == 0)
    {
      link = game->link[i];
    }
  }

  for (i = 0; i < MAX_OBJ && game->object[i] != NULL; i++)
  {
    if (strcmp(object_get_name(game->object[i]), objname) == 0)
    {
      object = game->object[i];
    }
  }

  if (!link || !object)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }
  
  if(playerloc_id==link_get_origin(link) && link_get_status(link)==CLOSE && player_isthere_object(game->player, object_get_id(object)) == TRUE && object_get_open(object)!= NO_ID){
    link_set_status(link,OPEN);
    player_delete_object(game->player, object_get_id(object));
    game_set_last_command_status(game, OK);
  } else{
    game_set_last_command_status(game, ERROR);
  }

  return;
}

void game_command_save(Game *game)
{
  char filename[255];

  if (!game)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  scanf("%s", filename);

  if (game_management_save(game, filename) == OK)
  {
    game_set_last_command_status(game, OK);
  }
  else
  {
    game_set_last_command_status(game, ERROR);
  }

  return;
}

void game_command_load(Game *game)
{
  char filename[255];

  if (!game)
  {
    game_set_last_command_status(game, ERROR);
    return;
  }

  scanf("%s", filename);

  if (game_management_load(game, filename))
  {
    game_set_last_command_status(game, OK);
  }
  else
  {
    game_set_last_command_status(game, ERROR);
  }

  return;
}

