/**
 * @brief It defines the game rules functions
 *
 * @file game_rules.h
 * @author Esther Martinez
 * @version 2.0
 * @date 27-04-2022
 * @copyright GNU Public License
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "game.h"
#include "types.h"


/**
 * @brief Executes the main rules
 * @author Esther Martinez
 * 
 * @param game a pointer to the game
 * @return TRUE if it is illuminated, FALSE if not
 */
void game_rules_main(Game *game);

#endif