/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "enemy.h"
#include "link.h"

/**
 * @brief Defines the structure _Game, formed by the player, the object, the spaces and the last command 
*/
typedef struct _Game Game;

/**
 * @brief It creates a new game
 * @author Esther Martinez
 *
 * game_create allocates memory for a new game
 *  and initializes its members
 * @return a new game, initialized
 */
Game *game_create();

/**
 * @brief It creates the game from file
 * @author Esther Martinez
 *
 * game_create_from_file creates a new game from a file given.
 * @param game a pointer to the game
 * @param filename name of the file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_create_from_file(Game *game, char *filename);

/**
 * @brief It updates the game
 * @author Esther Martinez
 *
 * game_update updates the game and all the content in it
 * @param game a pointer to the game
 * @param cmd command introduced
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_update(Game *game, T_Command cmd);

/**
 * @brief It destroys the game
 * @author Esther Martinez
 *
 * game_destroy frees the previous memory allocation
 *  for the game
 * @param game a pointer to the game that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_destroy(Game *game);

/**
 * @brief Check if the game is over
 * @author Esther Martinez
 *
 * This function indicates when is the game over
 *  for the game
 * @param game a pointer to the game
 * @return TRUE, if the game is over or FALSE if it is not.
 */
BOOL game_is_over(Game *game);

/**
 * @brief Prints the data
 * @author Esther Martinez
 *
 * This function prints all the data of the game
 * @param game a pointer to the game
 * @return It does not return anything as is type void
 */
void game_print_data(Game *game);

/**
 * @brief Gets the space
 * @author Esther Martinez
 *
 * This function gets the space id for the game
 * @param game a pointer to the game
 * @param id of an id given.
 * @return Data type space
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief Gets the object
 * @author Esther Martinez
 *
 * This function gets the space id for the game
 * @param game a pointer to the game
 * @param pos of the object
 * @return Data type object
 */
Object *game_get_object(Game *game, int pos);

/**
 * @brief Gets the player
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @return Data type player
 */
Player *game_get_player(Game *game);

/**
 * @brief Gets the enemy
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @return Data type enemy
 */
Enemy *game_get_enemy(Game *game);

/**
 * @brief Gets the number of non-NULL space
 * @author Pablo Vargas
 *
 * @param game a pointer to the game
 * @return the number of spaces
 */
int game_get_number_spaces(Game *game);

/**
 * @brief Gets the number of non-NULL links
 * @author Pablo Vargas
 *
 * @param game a pointer to the game
 * @return the number of links
 */
int game_get_number_links(Game *game);

/**
 * @brief Gets the number of non-NULL objects
 * @author Pablo Vargas
 *
 * @param game a pointer to the game
 * @return the number of objects
 */
int game_get_number_objects(Game *game);

/**
 * @brief Gets the player location
 * @author Esther Martinez
 *
 * This function gets the player location
 * @param game a pointer to the game
 * @return The id of the location of the player
 */
Id game_get_player_location(Game *game);

/**
 * @brief Gets the object location
 * @author Esther Martinez
 *
 * This function gets the object location
 * @param game a pointer to the game
 * @param id_object id of the object
 * @return The id of the location of the object
 */
Id game_get_object_location(Game *game, Id id_object);

/**
 * @brief Sets the object location
 * @author Esther Martinez
 *
 * This function sets the object location
 * @param game a pointer to the game
 * @param id_object a pointer to the id of the object
 * @param id_space a pointer to the id of the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_object_location(Game *game, Id id_space, Id id_object);

/**
 * @brief Gets the location of the enemy
 * @author Pablo Vargas
 *
 * This function gets the location of the enemy
 * @param game a pointer to the game
 * @return The id of the location of the enemy
 */
Id game_get_enemy_location(Game *game);

/**
 * @brief Gets the health of the enemy
 * @author Pablo Vargas
 *
 * This function gets the health of the enemy
 * @param game a pointer to the game
 * @return The id of the health of the enemy
 */
int game_get_enemy_health(Game *game);

/**
 * @brief Gets the health of the player
 * @author Pablo Vargas
 *
 * This function gets the health of the player
 * @param game a pointer to the game
 * @return The id of the health of the player
 */
int game_get_player_health(Game *game);

/**
 * @brief Gets the last command
 * @author Esther Martinez
 *
 * This function gets the last command
 * @param game a pointer to the game
 * @return The id of the last command, type T_Command
 */
T_Command game_get_last_command(Game *game);

/**
 * @brief Gets the last command status
 * @author Esther Martinez
 *
 * This function gets the last command status
 * @param game a pointer to the game
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_get_last_command_status(Game *game);

/**
 * @brief Sets the last command status
 * @author Esther Martinez
 *
 * This function sets the last command status
 * @param game a pointer to the game
 * @param status the status of the last command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_last_command_status(Game *game, STATUS status);

/**
 * @brief It gets the description of the game
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @return  a string with the description of the game
 */
const char *game_get_description(Game *game);

/**
 * @brief It sets the description of a game
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @param description a string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_description(Game *game, const char *description);

/**
 * @brief It gets the description of the illumination of the space
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @return  a string with the description of the illumination of the space
 */
const char *game_get_illudescription(Game *game);

/**
 * @brief It sets the description of the illumination of the space
 * @author Esther Martinez
 *
 * @param game a pointer to the game
 * @param illudescription a string with the description of the illumination of the space to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_illudescription(Game *game, const char *illudescription);

/**
 * @brief Establishes the location of the player
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param id location to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_player_location(Game *game, Id id);

/**
 * @brief Establishes the location of the enemy
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param id location to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_enemy_location(Game *game, Id id);

/**
 * @brief Establishes the health of the player
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i health to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_enemy_health(Game *game, int i);

/**
 * @brief Establishes the health of the player
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i health to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_player_health(Game *game, int i);

/**
 * @brief Obtains a certain space from game
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i Location of the space in the array
 * @return The space or NULL in case of error
 */
Space *game_get_space_at(Game *game, int i);

/**
 * @brief Establishes a space in a certain location of the array
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i location
 * @param space to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_space_at(Game *game, int i, Space *space);

/**
 * @brief Obtains a certain object from game
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i Location of the object in the array
 * @return The object or NULL in case of error
 */
Object *game_get_object_at(Game *game, int i);

/**
 * @brief Establishes a object in a certain location of the array
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param i location
 * @param object to be asigned
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_object_at(Game *game, int i, Object *object);

/**
 * @brief Gets the link from a position given
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param i the position of the link in the array of links
 * @return the link.
 */
Link *game_get_link_at(Game *game, int i);

/**
 * @brief Sets the link from a position given
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param i the position of the link in the array of links
 * @param link the link that we want to change
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_link_at(Game *game, int i, Link *link);

/**
 * @brief Sets the player
 * @author Alejandro Lopez
 * 
 * @param game a pointer to the game
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_player(Game *game, Player *player);

/**
 * @brief Sets the enemy
 * @author Alejandro Lopez
 * 
 * @param game a pointer to the game
 * @param enemy a pointer to the enemy
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_enemy(Game *game, Enemy *enemy);

/**
 * @brief Gets the status of the link
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param id the id of the actual space
 * @param dir the direction
 * @return OPEN, if the link is open or CLOSE if it is closed.
 */
LINKST game_get_connection_status(Game *game, Id id, DIRECTION dir);

/**
 * @brief Gets the next space of a direction given
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param id the id of the actual space
 * @param dir the direction
 * @return the id of the space
 */
Id game_get_connection(Game *game, Id id, DIRECTION dir);

/**
 * @brief Obtains the name of an object from the players inventory by the id
 * @author Jaime Sanchez Esteban
 *
 * @param game a pointer to the game
 * @param id identification of the object
 * @return The name of the object or NULL in case of error
 */
const char *game_get_player_object_name_by_id(Game *game, Id id);

/**
 * @brief Gets the illumination of a space using an id given
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param id the id of the actual space
 * @return TRUE if it is illuminated, FALSE if not
 */
BOOL game_get_illumination_of_space(Game *game, Id id);

/**
 * @brief Sets the illumination of a space using an space given
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @param space a pointer to the game
 * @param illumination thevalue of the illumination
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_illumination_of_space(Game *game, Space *space, BOOL illumination);

/**
 * @brief Gets if an object is turned or not
 * 
 * @param game a pointer to the game
 * @param object a pointer to the object
 * @return TRUE if it is illuminated, FALSE if not
 */
BOOL game_get_turned_of_object(Game *game, Object *object);

/**
 * @brief Sets if an object is turned or not
 * 
 * @param game a pointer to the game
 * @param object a pointer to the game
 * @param value a BOOL value
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_turned_of_object(Game *game, Object *object, BOOL value);

/**
 * @brief Gets if an object can illuminate
 * 
 * @param game a pointer to the game
 * @param object a pointer to the object
 * @return TRUE if it is illuminated, FALSE if not
 */
BOOL game_get_illuminate_of_object(Game *game, Object *object);

/**
 * @brief Sets if an object can illuminate
 * 
 * @param game a pointer to the game
 * @param object a pointer to the game
 * @param value a BOOL value
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_set_illuminate_of_object(Game *game, Object *object, BOOL value);

/**
 * @brief Checks if the inventory is empty
 * 
 * @param game a pointer to the game
 * @param player a pointer to the player
 * @return TRUE if it is illuminated, FALSE if not
 */
BOOL game_check_if_inventory_isEmpty(Game *game, Player *player);

/**
 * @brief Gets the object
 * 
 * @param game a pointer to the game
 * @param id the id of the object
 * @return an object
 */
Object* game_get_object_by_id(Game *game, Id id);

/**
 * @brief Tries to find objects in the inventory
 * 
 * @param game  a pointer to the game
 * @param id the id of the object
 * @return TRUE if it is in the inventory, FALSE if not
 */
BOOL game_get_isthere_object(Game *game,Id id);

/**
 * @brief Obtains the objects id by the name
 * @author Jaime Sánchez Esteban
 *
 * @param game a pointer to the game
 * @param name name of the object
 * @return returns the object id
 */
Id game_get_object_by_name(Game *game, char *name);
#endif
