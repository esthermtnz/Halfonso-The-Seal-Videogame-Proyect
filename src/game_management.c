/**
 * @brief It reads the game
 *
 * @file game_management.c
 * @author Esther Martínez
 * @version 2.0
 * @date 5-2-2021
 * @copyright GNU Public License
 */

/*We firstly include the libraries and the auxiliary files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"

/**
   Private functions
*/
BOOL int_to_bool(int i);

/**
 * @brief Adds the space
 * @author Esther Martínez
 *
 * @param game pointer to the game
 * @param space pointer to the space
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_add_space(Game *game, Space *space);

/**
 * @brief Adds the links
 * @author Esther Martínez
 *
 * @param game pointer to the game
 * @param link pointer to the link
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_add_link(Game *game, Link *link);

/**
 * @brief Adds the objects
 * @author Esther Martínez
 *
 * @param game pointer to the game
 * @param object pointer to the object
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_add_object(Game *game, Object *object);

/**
 * @brief Adds the player
 * @author Pablo Vargas
 *
 * @param game pointer to the game
 * @param player pointer to the player
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_add_player(Game *game, Player *player);

/**
 * @brief Adds the enemy
 * @author Pablo Vargas
 *
 * @param game pointer to the game
 * @param enemy pointer to the enemy
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_add_enemy(Game *game, Enemy *enemy);

/**
   Game interface implementation
*/

/*
 * ADD FUNCTIONS
 */

/** It introduce in the array of the game the spaces
 */
STATUS game_management_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game_get_space_at(game, i) != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game_set_space_at(game, i, space);

  return OK;
}

/** It introduce in the array of the game the links
 */
STATUS game_management_add_link(Game *game, Link *link)
{
  int i = 0;

  if (!game || !link)
  {
    return ERROR;
  }

  while (game_get_link_at(game, i) != NULL)
  {
    i++;
  }

  if (i >= MAX_LINKS)
  {
    return ERROR;
  }

  game_set_link_at(game, i, link);

  return OK;
}

/** It introduce in the array of the game the objects
 */
STATUS game_management_add_object(Game *game, Object *object)
{
  int i = 0;

  if (!game || !object)
  {
    return ERROR;
  }

  while (game_get_object_at(game, i) != NULL)
  {
    i++;
  }

  if (i >= MAX_OBJ)
  {
    return ERROR;
  }

  game_set_object_at(game, i, object);

  return OK;
}

STATUS game_management_add_player(Game *game, Player *player)
{
  if (!game || !player)
  {
    return ERROR;
  }

  game_set_player(game, player);

  return OK;
}

STATUS game_management_add_enemy(Game *game, Enemy *enemy)
{
  if (!game || !enemy)
  {
    return ERROR;
  }

  game_set_enemy(game, enemy);

  return OK;
}

/*
 * LOAD FUNCTIONS
 */

/** It sets loads spaces in the game and deefines the map and spaces
 */
STATUS game_management_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char illudescription[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
  BOOL illumination = FALSE;
  Space *space = NULL;
  STATUS status = OK;
  int i;

  /*checks the filename*/
  if (!filename)
  {
    return ERROR;
  }
  /*opens and reads the file */
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }
  /*defines the map limits*/
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      illumination = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(illudescription, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%d|%s\n", id, name, description, illumination, illudescription);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_description(space, description);
        space_set_illumination(space, illumination);
        space_set_illudescription(space, illudescription);

        for (i = 0; i < 5; i++)
        {
          toks = strtok(NULL, "|");
          space_set_gdesc(space, toks, i); /* Adds the graphic description*/
        }

        game_management_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/** It loads links in the game and defines the map and spaces
 */
STATUS game_management_load_links(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, origin = NO_ID, destination = NO_ID;
  DIRECTION direction = N;
  LINKST openclose = CLOSE;
  Link *link = NULL;
  STATUS status = OK;

  /*checks the filename*/
  if (!filename)
  {
    return ERROR;
  }
  /*opens and reads the file */
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }
  /*defines the map limits*/
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#l:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      origin = atol(toks);
      toks = strtok(NULL, "|");
      destination = atol(toks);
      toks = strtok(NULL, "|");
      direction = atol(toks);
      toks = strtok(NULL, "|");
      openclose = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, origin, destination, direction, openclose);
#endif
      link = link_create(id);
      if (link != NULL)
      {

        game_management_add_link(game, link);
        link_set_name(link, name);
        link_set_origin(link, origin);
        link_set_destination(link, destination);
        link_set_direction(link, direction);
        link_set_status(link, openclose);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/** It sets loads objects in the game and defines the map and objects
 */
STATUS game_management_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space = NO_ID, dependency = NO_ID, open = NO_ID;
  int movable = 0, illuminate = 0, turnedon = 0;
  Object *object = NULL;
  STATUS status = OK;

  /*checks the filename*/
  if (!filename)
  {
    return ERROR;
  }
  /*opens and reads the file */
  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("ERROR");
    return ERROR;
  }
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      movable = atol(toks);
      toks = strtok(NULL, "|");
      dependency = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "|");
      illuminate = atol(toks);
      toks = strtok(NULL, "|");
      turnedon = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, space);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        game_set_object_location(game, space, id);
        object_set_description(object, description);
        object_set_movable(object, movable);
        object_set_dependency(object, dependency);
        object_set_open(object, open);
        object_set_illuminate(object, illuminate);
        object_set_turnedon(object, turnedon);
        game_management_add_object(game, object);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_player(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space = NO_ID;
  Player *player = NULL;
  int health, max_objects;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");

  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      max_objects = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, space);
#endif
      player = player_create(id);
      if (player != NULL)
      {
        game_management_add_player(game, player);
        player_set_name(player, name);
        game_set_player_location(game, space);
        player_set_health(player, health);
        player_set_max_inv(player, max_objects);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;

  return OK;
}

STATUS game_management_load_enemy(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space = NO_ID;
  Enemy *enemy = NULL;
  int health;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");

  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#e:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, space);
#endif
      enemy = enemy_create(id);
      if (enemy != NULL)
      {
        game_management_add_enemy(game, enemy);
        enemy_set_name(enemy, name);
        game_set_enemy_location(game, space);
        enemy_set_health(enemy, health);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;

  return OK;
}

STATUS game_management_save(Game *game, char *filename)
{
  FILE *file = NULL;
  Space *space = NULL;
  Object *object = NULL;
  Link *link = NULL;
  Player *player = NULL;
  Enemy *enemy = NULL;
  char str[255];
  char str2[255] = "\n";
  int i = 0;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "w");
  if (file == NULL)
  {
    return ERROR;
  }

  /* Saves the link's data */
  for (i = 0; i < game_get_number_links(game); i++)
  {
    link = game_get_link_at(game, i);

    sprintf(str, "#l:%ld|%s|%ld|%ld|%d|%d|\n", link_get_id(link), link_get_name(link), link_get_origin(link), link_get_destination(link), link_get_direction(link), link_get_status(link));

    fprintf(file, "%s", str);
  }
  fprintf(file, "%s", str2);

  /* Saves the space's data */
  for (i = 0; i < game_get_number_spaces(game); i++)
  {
    space = game_get_space_at(game, i);

    sprintf(str, "#s:%ld|%s|%s|%d|%s|%s|%s|%s|%s|%s|\n", space_get_id(space), space_get_name(space), space_get_description(space), space_get_illumination(space), space_get_illudescription(space), space_get_gdesc(space, 0), space_get_gdesc(space, 1), space_get_gdesc(space, 2), space_get_gdesc(space, 3), space_get_gdesc(space, 4));

    fprintf(file, "%s", str);
  }

  fprintf(file, "%s", str2);

  /* Saves the object's data */
  for (i = 0; i < game_get_number_objects(game); i++)
  {
    object = game_get_object_at(game, i);

    sprintf(str, "#o:%ld|%s|%ld|%s|%d|%ld|%ld|%d|%d|\n", object_get_id(object), object_get_name(object), game_get_object_location(game, object_get_id(object)), object_get_description(object), object_get_movable(object), object_get_dependency(object), object_get_open(object), object_get_illuminate(object), object_get_turnedon(object));

    fprintf(file, "%s", str);
  }

  fprintf(file, "%s", str2);

  /* Saves the player's data */
  player = game_get_player(game);
  sprintf(str, "#p:%ld|%s|%ld|%d|%d|\n", player_get_id(player), player_get_name(player), player_get_location(player), player_get_health(player), player_get_max_inv(player));
  fprintf(file, "%s", str);

  /* Saves the enemy's data */
  enemy = game_get_enemy(game);
  sprintf(str, "#e:%ld|%s|%ld|%d|\n", enemy_get_id(enemy), enemy_get_name(enemy), enemy_get_location(enemy), enemy_get_health(enemy));
  fprintf(file, "%s", str);

  fclose(file);

  return OK;
}

STATUS game_management_load(Game *game, char *filename)
{
  int i = 0;

  if (!filename)
  {
    return ERROR;
  }

  if (!game)
  {
    return ERROR;
  }

  if (!game_management_load_links(game, filename))
    return ERROR;

  if (!game_management_load_spaces(game, filename))
    return ERROR;

  if (!game_management_load_objects(game, filename))
    return ERROR;

  if (!game_management_load_player(game, filename))
    return ERROR;

  if (!game_management_load_enemy(game, filename))
    return ERROR;

  for (i = 0; i < game_get_number_objects(game); i++)
  {
    Object *object = game_get_object_at(game, i);
    Id obj_id = object_get_id(object);
    if (game_get_object_location(game, obj_id) == NO_ID)
    {
      player_add_object(game_get_player(game), obj_id);
    }
  }

  return OK;
}

BOOL int_to_bool(int i)
{
  if (i == 1)
    return TRUE;
  else
    return FALSE;
}
