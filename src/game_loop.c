/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

/*Includes all the libraries and .h needed*/
#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game_rules.h"
#include "game.h"
#include "command.h"

/**
 * @brief This function initiates the loop of the game.
 *
 * @param game a pointer to game
 * @param gengine a pointer to the Graphic_engine
 * @param file_name a pointer to the name of the file
 * @return Returns an integer
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 * @brief This function runs the loop of the game.
 *
 * @param game a pointer to game
 * @param gengine a pointer to the Graphic_engine
 */
void game_loop_run(Game *game, Graphic_engine *gengine, char *arch);

/**
 * @brief This function cleans up all the game.
 *
 * @param game a pointer to game
 * @param gengine a pointer to the Graphic_engine
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 * @brief Main function
 *
 * @param argc and interger
 * @param argv Arguments introduced when executing the game
 */
int main(int argc, char *argv[])
{
  Game *game;
  Graphic_engine *gengine;
  FILE *f;
  game = game_create();

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
  
  if (argv[2])
  {
  	f = fopen(argv[2], "w");
  	fclose(f);
  }

  if (!game_loop_init(game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine, argv[2]);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  /*if there is any problem loading the file it prints an error message */
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }
  /*if there is any problem inizializing the graphic engine then it prints an error message)*/
  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }
  /*however, if everything is inicialised correctly then returns 0;*/
  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, char *arch)
{
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(game))
  { /*while the command is not exit or the game is over:*/

    graphic_engine_paint_game(gengine, game, arch); /*the graphic engine keeps drawing the game map*/
    command = command_get_user_input();        /*the command is the introduced by the user in the command console*/
    game_update(game, command);               /*the game keeps updating will the loop runs*/
    game_rules_main(game);                    /*the game checks the rules of the game*/
  }
}

void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);             /*the game is destroyed*/
  graphic_engine_destroy(gengine); /*the graphic engine is destroyed*/
}
