/**
 * @brief It defines the player functionality
 *
 * @file player.h
 * @author Pablo Vargas
 * @version 1.0
 * @date 9-2-2022
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "types.h"
#include "inventory.h"
/**
 * @brief Structure of Player
 */
typedef struct _Player Player;

/**
 * @brief It creates a new player
 * @author Pablo Vargas
 *
 * player_create allocates memory for a new player
 *  and initializes its members
 * @param id the identification number for the new player
 * @return a new player, initialized
 */
Player *player_create(Id id);

/**
 * @brief It destroys the player
 * @author Pablo Vargas
 *
 * player_destroy frees the previous memory allocation
 *  for the player
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_destroy(Player *player);

/**
 * @brief It gets the id of the player
 * @author Pablo Vargas
 *
 * @param player a pointer to the player
 * @return the id of player
 */
Id player_get_id(Player *player);

/**
 * @brief It sets the name of a player
 * @author Pablo Vargas
 *
 * @param player a pointer to the player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_name(Player *player, char *name);

/**
 * @brief It gets the name of an player
 * @author Pablo Vargas
 *
 * @param player a pointer to the player
 * @return  a string with the name of the player
 */
const char *player_get_name(Player *player);

/**
 * @brief It adds a new object to the inventory
 * @author Jaime Sánchez Esteban
 *
 * @param player a pointer to the player
 * @param value of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_add_object(Player *player, Id value);

/**
 * @brief It deletes a object from the player inventory
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @param id id of the object to be removed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_delete_object(Player *player, Id id);

/**
 * @brief Establish the maximum capacity of the player's inventory
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @param n inventory capacity
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_max_inv(Player *player, int n);

/**
 * @brief It gets the maximum capacity of the player's inventory
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @return The capacity or -1 in case of error
 */
int player_get_max_inv(Player *player);

/**
 * @brief Checks if a certain object is contained in the player's inventory
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @param id item to search
 * @return TRUE if the item is finded or FALSE if not
 */
BOOL player_isthere_object(Player *player, Id id);

/**
 * @brief Checks if the maximum capacity of the inventory has been reached
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @return TRUE if it has or FALSE if not
 */
BOOL player_inventory_is_full(Player *player);

/**
 * @brief Checks if the inventory is empty
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @return TRUE if it is or FALSE if not
 */
BOOL player_inventory_is_empty(Player *player);

/**
 * @brief It sets the player location
 * @author Pablo Vargas
 *
 * This function sets the player's location of a one given as an argument.
 * @param player a pointer to the player
 * @param id of an id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_location(Player *player, Id id);

/**
 * @brief It gets the player location
 * @author Pablo Vargas
 *
 * This function shows the player's location.
 * @param player a pointer to the player
 * @return the player location in id format
 */
Id player_get_location(Player *player);

/**
 * @brief It sets the player health
 * @author Pablo Vargas
 *
 * This function gets the player's health.
 * @param player a pointer to the player
 * @param health value to be assigned as health of the player
 * @return Ok if everything goes good or ERROR if there was some mistake
 */
STATUS player_set_health(Player *player, int health);

/**
 * @brief It gets the player health
 * @author Pablo Vargas
 *
 * This function gets the player's health.
 * @param player a pointer to the player
 * @return the player health in int format
 */
int player_get_health(Player *player);


/**
 * @brief It prints the player information
 * @author Pablo Vargas
 *
 * This function shows the id and name of the player.
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_print(Player *player);

/**
 * @brief Obtains a certain object id from the players inventory
 * @author Jaime Sanchez Esteban
 *
 * @param player a pointer to the player
 * @param i position of the object in the inventory
 * @return The id of the object or NO_ID in case of ERROR
 */
Id player_get_x_object(Player *player, int i);
#endif
