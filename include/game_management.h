
/**
 * @brief It defines the game management interface
 *
 * @file game_management.h
 * @author Esther Martínez
 * @date 5-2-2022
 */
#ifndef GAME_management
#define GAME_management

/*We include the libaries and the auxiliary files*/
#include "types.h"
#include "space.h"
#include "object.h"
#include "game.h"
#include "inventory.h"
#include "link.h"

/**
 * @brief Loads the spaces
 * @author Esther Martínez
 *
 * This function loads the spaces of the game after reading them from a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_spaces(Game *game, char *filename);

/**
 * @brief Loads the objects
 * @author Esther Martínez
 *
 * This function loads the objects of the game after reading them from a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_objects(Game *game, char *filename);

/**
 * @brief Loads the links
 * @author Esther Martínez
 *
 * This function loads the links of the game after reading them from a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_links(Game *game, char *filename);

/**
 * @brief Loads the enemy
 * @author Pablo Vargas
 *
 * This function loads the enemy of the game after reading it from a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_enemy(Game *game, char *filename);

/**
 * @brief Loads the player
 * @author Pablo Vargas
 *
 * This function loads the player of the game after reading it from a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_player(Game *game, char *filename);

/**
 * @brief Saves the game
 * @author Pablo Vargas
 *
 * This function saves the game in a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_save(Game *game, char *filename);

/**
 * @brief Loads the game
 * @author Pablo Vargas
 *
 * This function loads the game in a file.
 * @param game pointer to the game
 * @param filename pointer to the filename, type char
 * @return return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load(Game *game, char *filename);

#endif
