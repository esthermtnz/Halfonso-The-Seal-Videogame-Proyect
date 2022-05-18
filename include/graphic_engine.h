/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
 * @brief Declaration of structure Graphic_Engine
 */
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates and inicalize a new pointer
 * @author Pablo Vargas
 *
 * @return a graphic engine pointer inicializes
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys the game engine
 * @author Pablo Vargas
 *
 * This function deletes the screen painting
 * @param ge Graphic_engine pointer
 * @return does not return anything as is type void
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Paints the game engine
 * @author Pablo Vargas
 *
 * This function paints the whole screen map
 * @param ge Graphic_engine pointer
 * @param game pointer to the game
 * @return does not return anything as is type void
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game, char *arch);

/**
 * @brief Writes the commands in the game engine
 * @author Pablo Vargas
 *
 * This function writes the commands in the game engine
 * @param ge Graphic_engine pointer
 * @param str char pointer
 * @return does not return anything as is type void
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
