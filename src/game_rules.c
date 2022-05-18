/**
 * @brief It implements the game_rules interface and all the associated calls
 * for each command
 *
 * @file game_rules.c
 * @author Esther Masrtinez
 * @version 2.0
 * @date 27-04-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game_rules.h"
#include "game.h"

void game_rules_main(Game *game)
{
    int i = 0;

    /*If enemy dies all the rooms get illuminated automatically*/
    if (game_get_enemy_health(game) == 0)
    {
        for (i = 0; i < MAX_SPACES && game_get_space_at(game,i) != NULL; i++)
        {
            game_set_illumination_of_space(game,game_get_space_at(game,i),TRUE);
        }
    }
    /*Uso de la pocion curativa*/
    if (player_isthere_object(game_get_player(game), game_get_object_by_name(game, "pocion")))
    {
    	game_set_player_health(game, 10);
    	player_delete_object(game_get_player(game), 4);
    }
    /*Efecto de curacion del lago*/
    if (game_get_player_location(game) == 123)
    {
    	game_set_player_health(game, 10);
    }
    
    return;
}
