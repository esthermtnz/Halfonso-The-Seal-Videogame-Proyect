/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"
/**
 * @brief number of rows
 */
#define ROWS 32
/**
 * @brief number of cols
 */
#define COLUMNS 82
/**
 * @brief Structure with the parameters needed to print the game in the terminal
 */
struct _Graphic_engine
{
  Area *map;      /*!< map area */
  Area *descript; /*!< descript area */
  Area *banner;   /*!< banner area */
  Area *help;     /*!< help area */
  Area *feedback; /*!< feedback area */
};

/**
   Private functions
*/
void graphic_engine_id_objects(Graphic_engine *ge, Space *s)
{
}

/* Initializes the screen area */

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 19);
  ge->descript = screen_area_init(50, 1, 31, 19);
  ge->banner = screen_area_init(31, 21, 23, 1);
  ge->help = screen_area_init(1, 22, 80, 4);
  ge->feedback = screen_area_init(1, 27, 80, 4);

  return ge;
}
/* Destroys the screen area */

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/* Paints the whole game */

void graphic_engine_paint_game(Graphic_engine *ge, Game *game, char *arch)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, enem_loc = NO_ID, player_loc = NO_ID, id_west = NO_ID, id_east = NO_ID;
  Id object_loc = NO_ID;
  Space *space_act = NULL;
  char o1[50], o2[50], o3[50], o4[50], o5[50], o6[50], o7[50], o8[50], o9[50], o10[50], o11[50], o12[50], o13[50], o14[50], o15[50], o16[50], o17[50], o18[50], o19[50], o20[50]; /*the size has been set to 50 to avoid string overflow*/
  char str[1020], descr[150], illudescr[150];
  T_Command last_cmd = UNKNOWN;
  STATUS statuslc;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i, j;
  FILE *log;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = game_get_connection(game, space_get_id(space_act), N);
    id_next = game_get_connection(game, space_get_id(space_act), S);
    id_west = game_get_connection(game, space_get_id(space_act), W);
    id_east = game_get_connection(game, space_get_id(space_act), E);


    strcpy(o1, ""); /*Firstly the object o1 it's not painted*/
    strcpy(o2, ""); /*Firstly the object o2 it's not painted*/
    strcpy(o3, ""); /*Firstly the object o3 it's not painted*/
    strcpy(o4, ""); /*Firstly the object o4 it's not painted*/
    strcpy(o5, ""); /*Firstly the object o5 it's not painted*/
    strcpy(o6, ""); /*Firstly the object o6 it's not painted*/
    strcpy(o7, ""); /*Firstly the object o7 it's not painted*/
    strcpy(o8, ""); /*Firstly the object o8 it's not painted*/
    strcpy(o9, ""); /*Firstly the object o9 it's not painted*/
    strcpy(o10, ""); /*Firstly the object o10 it's not painted*/
    strcpy(o11, ""); /*Firstly the object o11 it's not painted*/
    strcpy(o12, ""); /*Firstly the object o12 it's not painted*/
    strcpy(o13, ""); /*Firstly the object o13 it's not painted*/
    strcpy(o14, ""); /*Firstly the object o14 it's not painted*/
    strcpy(o15, ""); /*Firstly the object o15 it's not painted*/
    strcpy(o16, ""); /*Firstly the object o16 it's not painted*/
    strcpy(o17, ""); /*Firstly the object o17 it's not painted*/
    strcpy(o18, ""); /*Firstly the object o18 it's not painted*/
    strcpy(o19, ""); /*Firstly the object o19 it's not painted*/
    strcpy(o20, ""); /*Firstly the object o20 it's not painted*/


    for (i = 0; i < MAX_OBJ; i++)
    {
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_back)
      { /*if the object location is the same as the id of the space at the back*/
        if (i == 0)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o1, object_get_name(game_get_object(game, i))); /*copies in o1 the name of the object 1*/
        }
        if (i == 1)
        {
          strcpy(o2, object_get_name(game_get_object(game, i))); /*copies in o2 the name of the object 2*/
        }
        if (i == 2)
        {
          strcpy(o3, object_get_name(game_get_object(game, i))); /*copies in o3 the name of the object 3*/
        }
        if (i == 3)
        {
          strcpy(o4, object_get_name(game_get_object(game, i))); /*copies in o4 the name of the object 4*/
        }
        if (i == 4)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o5, object_get_name(game_get_object(game, i))); /*copies in o5 the name of the object 1*/
        }
        if (i == 5)
        {
          strcpy(o6, object_get_name(game_get_object(game, i))); /*copies in o6 the name of the object 2*/
        }
        if (i == 6)
        {
          strcpy(o7, object_get_name(game_get_object(game, i))); /*copies in o7 the name of the object 3*/
        }
        if (i == 7)
        {
          strcpy(o8, object_get_name(game_get_object(game, i))); /*copies in o8 the name of the object 4*/
        }
        if (i == 8)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o9, object_get_name(game_get_object(game, i))); /*copies in o9 the name of the object 1*/
        }
        if (i == 9)
        {
          strcpy(o10, object_get_name(game_get_object(game, i))); /*copies in o10 the name of the object 2*/
        }
        if (i == 10)
        {
          strcpy(o11, object_get_name(game_get_object(game, i))); /*copies in o11 the name of the object 3*/
        }
        if (i == 11)
        {
          strcpy(o12, object_get_name(game_get_object(game, i))); /*copies in o12 the name of the object 4*/
        }
        if (i == 12)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o13, object_get_name(game_get_object(game, i))); /*copies in o13 the name of the object 1*/
        }
        if (i == 13)
        {
          strcpy(o14, object_get_name(game_get_object(game, i))); /*copies in o14 the name of the object 2*/
        }
        if (i == 14)
        {
          strcpy(o15, object_get_name(game_get_object(game, i))); /*copies in o15 the name of the object 3*/
        }
        if (i == 15)
        {
          strcpy(o16, object_get_name(game_get_object(game, i))); /*copies in o16 the name of the object 4*/
        }
        if (i == 16)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o17, object_get_name(game_get_object(game, i))); /*copies in o17 the name of the object 1*/
        }
        if (i == 17)
        {
          strcpy(o18, object_get_name(game_get_object(game, i))); /*copies in o18 the name of the object 2*/
        }
        if (i == 18)
        {
          strcpy(o19, object_get_name(game_get_object(game, i))); /*copies in o19 the name of the object 3*/
        }
        if (i == 19)
        {
          strcpy(o20, object_get_name(game_get_object(game, i))); /*copies in o20 the name of the object 4*/
        }
      }
    }

    if (id_back != NO_ID)
    {
      sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_back), 3));
      screen_area_puts(ge->map, str);
      sprintf(str, "              |%s   %2d|", space_get_gdesc(game_get_space(game, id_back), 4),(int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "              +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                      ^");
      screen_area_puts(ge->map, str);
    }
    else
    {
      sprintf(str, "              ");
      screen_area_puts(ge->map, str);
      sprintf(str, "              ");
      screen_area_puts(ge->map, str);
      sprintf(str, "              ");
      screen_area_puts(ge->map, str);
      sprintf(str, "              ");
      screen_area_puts(ge->map, str);
    }

    strcpy(o1, ""); /*Firstly the object o1 it's not painted*/
    strcpy(o2, ""); /*Firstly the object o2 it's not painted*/
    strcpy(o3, ""); /*Firstly the object o3 it's not painted*/
    strcpy(o4, ""); /*Firstly the object o4 it's not painted*/
    strcpy(o5, ""); /*Firstly the object o5 it's not painted*/
    strcpy(o6, ""); /*Firstly the object o6 it's not painted*/
    strcpy(o7, ""); /*Firstly the object o7 it's not painted*/
    strcpy(o8, ""); /*Firstly the object o8 it's not painted*/
    strcpy(o9, ""); /*Firstly the object o9 it's not painted*/
    strcpy(o10, ""); /*Firstly the object o10 it's not painted*/
    strcpy(o11, ""); /*Firstly the object o11 it's not painted*/
    strcpy(o12, ""); /*Firstly the object o12 it's not painted*/
    strcpy(o13, ""); /*Firstly the object o13 it's not painted*/
    strcpy(o14, ""); /*Firstly the object o14 it's not painted*/
    strcpy(o15, ""); /*Firstly the object o15 it's not painted*/
    strcpy(o16, ""); /*Firstly the object o16 it's not painted*/
    strcpy(o17, ""); /*Firstly the object o17 it's not painted*/
    strcpy(o18, ""); /*Firstly the object o18 it's not painted*/
    strcpy(o19, ""); /*Firstly the object o19 it's not painted*/
    strcpy(o20, ""); /*Firstly the object o20 it's not painted*/

    for (i = 0; i < MAX_OBJ; i++)
    {
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_act)
      {
        if (i == 0)
        {
          strcpy(o1, object_get_name(game_get_object(game, i))); /*copies in o1 the name of the object 1*/
        }
        if (i == 1)
        {
          strcpy(o2, object_get_name(game_get_object(game, i))); /*copies in o2 the name of the object 2*/
        }
        if (i == 2)
        {
          strcpy(o3, object_get_name(game_get_object(game, i))); /*copies in o3 the name of the object 3*/
        }
        if (i == 3)
        {
          strcpy(o4, object_get_name(game_get_object(game, i))); /*copies in o4 the name of the object 4*/
        }
        if (i == 4)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o5, object_get_name(game_get_object(game, i))); /*copies in o5 the name of the object 1*/
        }
        if (i == 5)
        {
          strcpy(o6, object_get_name(game_get_object(game, i))); /*copies in o6 the name of the object 2*/
        }
        if (i == 6)
        {
          strcpy(o7, object_get_name(game_get_object(game, i))); /*copies in o7 the name of the object 3*/
        }
        if (i == 7)
        {
          strcpy(o8, object_get_name(game_get_object(game, i))); /*copies in o8 the name of the object 4*/
        }
        if (i == 8)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o9, object_get_name(game_get_object(game, i))); /*copies in o9 the name of the object 1*/
        }
        if (i == 9)
        {
          strcpy(o10, object_get_name(game_get_object(game, i))); /*copies in o10 the name of the object 2*/
        }
        if (i == 10)
        {
          strcpy(o11, object_get_name(game_get_object(game, i))); /*copies in o11 the name of the object 3*/
        }
        if (i == 11)
        {
          strcpy(o12, object_get_name(game_get_object(game, i))); /*copies in o12 the name of the object 4*/
        }
        if (i == 12)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o13, object_get_name(game_get_object(game, i))); /*copies in o13 the name of the object 1*/
        }
        if (i == 13)
        {
          strcpy(o14, object_get_name(game_get_object(game, i))); /*copies in o14 the name of the object 2*/
        }
        if (i == 14)
        {
          strcpy(o15, object_get_name(game_get_object(game, i))); /*copies in o15 the name of the object 3*/
        }
        if (i == 15)
        {
          strcpy(o16, object_get_name(game_get_object(game, i))); /*copies in o16 the name of the object 4*/
        }
        if (i == 16)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o17, object_get_name(game_get_object(game, i))); /*copies in o17 the name of the object 1*/
        }
        if (i == 17)
        {
          strcpy(o18, object_get_name(game_get_object(game, i))); /*copies in o18 the name of the object 2*/
        }
        if (i == 18)
        {
          strcpy(o19, object_get_name(game_get_object(game, i))); /*copies in o19 the name of the object 3*/
        }
        if (i == 19)
        {
          strcpy(o20, object_get_name(game_get_object(game, i))); /*copies in o20 the name of the object 4*/
        }
      }
    }

    if (id_act != NO_ID)
    {
      if (id_east == NO_ID && id_west == NO_ID)
      {
        sprintf(str, "              +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "              | <(owo)>    %2d|", (int)id_act);
          screen_area_puts(ge->map, str);
        
        if (game_get_enemy_location(game) == id_act && game_get_enemy_health(game) > 0)
        {
          sprintf(str, "              |%s(0vv0)|", space_get_gdesc(game_get_space(game, id_act), 0));
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_act), 0));
          screen_area_puts(ge->map, str);
        }
        sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_act), 1));
        screen_area_puts(ge->map, str);

        if ((id_east != -1) && (id_west == -1))
        {
          sprintf(str, "              |%s      | >", space_get_gdesc(game_get_space(game, id_act), 2));
          screen_area_puts(ge->map, str);
        }
        else if ((id_east == -1) && (id_west != -1))
        {
          sprintf(str, "            < |%s      |", space_get_gdesc(game_get_space(game, id_act), 2));
          screen_area_puts(ge->map, str);
        }
        else if ((id_east != -1) && (id_west != -1))
        {
          sprintf(str, "            < |%s      |  >", space_get_gdesc(game_get_space(game, id_act), 2));
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_act), 2));
          screen_area_puts(ge->map, str);
        }
        sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_act), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "              |%s      |", space_get_gdesc(game_get_space(game, id_act), 4));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s|", o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19, o20);
          screen_area_puts(ge->map, str);

        sprintf(str, "              +---------------+");
        screen_area_puts(ge->map, str);
      }
      else if (id_east != NO_ID && id_west == NO_ID)
      {
        sprintf(str, "              +---------------+   +---------");
        screen_area_puts(ge->map, str);
        sprintf(str, "              | <(owo)>    %2d|   |%2d      ", (int)id_act, (int)id_east);
          screen_area_puts(ge->map, str);
        if (game_get_enemy_location(game) == id_act && game_get_enemy_health(game) > 0)
        {
        sprintf(str, "              |%s(0vv0)|   |%s", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), 0));
          screen_area_puts(ge->map, str);
        }
        else
        {
        sprintf(str, "              |%s      |   |%s", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), 0));
          screen_area_puts(ge->map, str);
        }
        sprintf(str, "              |%s      |   |%s", space_get_gdesc(game_get_space(game, id_act), 1), space_get_gdesc(game_get_space(game, id_east), 1));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s      | > |%s", space_get_gdesc(game_get_space(game, id_act), 2), space_get_gdesc(game_get_space(game, id_east), 2));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s      |   |%s", space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_east), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, "              |%s      |   |%s", space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_east), 4));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s|", o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19, o20);
          screen_area_puts(ge->map, str);

        sprintf(str, "              +---------------+   +---------");
        screen_area_puts(ge->map, str);
      }
      else if (id_east != NO_ID && id_west != NO_ID)
      {
        sprintf(str, "----------+   +---------------+   +---------");
        screen_area_puts(ge->map, str);
        sprintf(str, "       %2d|   | <(owo)>    %2d|   |%2d     ", (int)id_west, (int)id_act, (int)id_east);
          screen_area_puts(ge->map, str);
        if (game_get_enemy_location(game) == id_act && game_get_enemy_health(game) > 0)
        {
          sprintf(str, "     |  |%s(0vv0)|   |%s   ", space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), 0));
          screen_area_puts(ge->map, str);
        }
        else
        {
        sprintf(str, " %s|   |%s      |   |%s   ", space_get_gdesc(game_get_space(game, id_west), 0), space_get_gdesc(game_get_space(game, id_act), 0), space_get_gdesc(game_get_space(game, id_east), 0));
          screen_area_puts(ge->map, str);
        }
        sprintf(str, " %s|   |%s      |   |%s   ",space_get_gdesc(game_get_space(game, id_west), 1), space_get_gdesc(game_get_space(game, id_act), 1), space_get_gdesc(game_get_space(game, id_east), 1));
        screen_area_puts(ge->map, str);

        sprintf(str, " %s| < |%s      | > |%s   ",space_get_gdesc(game_get_space(game, id_west), 2), space_get_gdesc(game_get_space(game, id_act), 2), space_get_gdesc(game_get_space(game, id_east), 2));
        screen_area_puts(ge->map, str);

        sprintf(str, " %s|   |%s      |   |%s   ",space_get_gdesc(game_get_space(game, id_west), 3),space_get_gdesc(game_get_space(game, id_act), 3), space_get_gdesc(game_get_space(game, id_east), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, " %s|   |%s      |   |%s   ",space_get_gdesc(game_get_space(game, id_west), 4), space_get_gdesc(game_get_space(game, id_act), 4), space_get_gdesc(game_get_space(game, id_east), 4));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s|", o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19, o20);
          screen_area_puts(ge->map, str);

        sprintf(str, "----------+   +---------------+   +---------");
        screen_area_puts(ge->map, str);
      }
      else if (id_east == NO_ID && id_west != NO_ID)
      {
        sprintf(str, "----------+   +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "       %2d|   | <(owo)>    %2d|", (int)id_west, (int)id_act);
          screen_area_puts(ge->map, str);
        if (game_get_enemy_location(game) == id_act && game_get_enemy_health(game) > 0)
        {
          sprintf(str, " %s|   |%s(0vv0)|", space_get_gdesc(game_get_space(game, id_west), 0), space_get_gdesc(game_get_space(game, id_act), 0));
          screen_area_puts(ge->map, str);
        }
        else
        {
        sprintf(str, " %s|   |%s      |", space_get_gdesc(game_get_space(game, id_west), 0), space_get_gdesc(game_get_space(game, id_act), 0));
          screen_area_puts(ge->map, str);
        }
        sprintf(str, " %s|   |%s      |", space_get_gdesc(game_get_space(game, id_west), 1), space_get_gdesc(game_get_space(game, id_act), 1));
        screen_area_puts(ge->map, str);

        sprintf(str, " %s| < |%s      |", space_get_gdesc(game_get_space(game, id_west), 2), space_get_gdesc(game_get_space(game, id_act), 2));
        screen_area_puts(ge->map, str);

        sprintf(str, " %s|   |%s      |", space_get_gdesc(game_get_space(game, id_west), 3), space_get_gdesc(game_get_space(game, id_act), 3));
        screen_area_puts(ge->map, str);
        sprintf(str, " %s|   |%s      |", space_get_gdesc(game_get_space(game, id_west), 4), space_get_gdesc(game_get_space(game, id_act), 4));
        screen_area_puts(ge->map, str);

        sprintf(str, "              |%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s|", o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19, o20);
          screen_area_puts(ge->map, str);

        sprintf(str, "----------+   +---------------+");
        screen_area_puts(ge->map, str);
      }
    }

    strcpy(o1, ""); /*Firstly the object o1 it's not painted*/
    strcpy(o2, ""); /*Firstly the object o2 it's not painted*/
    strcpy(o3, ""); /*Firstly the object o3 it's not painted*/
    strcpy(o4, ""); /*Firstly the object o4 it's not painted*/
    strcpy(o5, ""); /*Firstly the object o5 it's not painted*/
    strcpy(o6, ""); /*Firstly the object o6 it's not painted*/
    strcpy(o7, ""); /*Firstly the object o7 it's not painted*/
    strcpy(o8, ""); /*Firstly the object o8 it's not painted*/
    strcpy(o9, ""); /*Firstly the object o9 it's not painted*/
    strcpy(o10, ""); /*Firstly the object o10 it's not painted*/
    strcpy(o11, ""); /*Firstly the object o11 it's not painted*/
    strcpy(o12, ""); /*Firstly the object o12 it's not painted*/
    strcpy(o13, ""); /*Firstly the object o13 it's not painted*/
    strcpy(o14, ""); /*Firstly the object o14 it's not painted*/
    strcpy(o15, ""); /*Firstly the object o15 it's not painted*/
    strcpy(o16, ""); /*Firstly the object o16 it's not painted*/
    strcpy(o17, ""); /*Firstly the object o17 it's not painted*/
    strcpy(o18, ""); /*Firstly the object o18 it's not painted*/
    strcpy(o19, ""); /*Firstly the object o19 it's not painted*/
    strcpy(o20, ""); /*Firstly the object o20 it's not painted*/

    for (i = 0; i < MAX_OBJ; i++)
    {
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_next)
      {
        if (i == 0)
        {
          strcpy(o1, object_get_name(game_get_object(game, i))); /*copies in o1 the name of the object 1*/
        }
        if (i == 1)
        {
          strcpy(o2, object_get_name(game_get_object(game, i))); /*copies in o2 the name of the object 2*/
        }
        if (i == 2)
        {
          strcpy(o3, object_get_name(game_get_object(game, i))); /*copies in o3 the name of the object 3*/
        }
        if (i == 3)
        {
          strcpy(o4, object_get_name(game_get_object(game, i))); /*copies in o4 the name of the object 4*/
        }
        if (i == 4)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o5, object_get_name(game_get_object(game, i))); /*copies in o5 the name of the object 1*/
        }
        if (i == 5)
        {
          strcpy(o6, object_get_name(game_get_object(game, i))); /*copies in o6 the name of the object 2*/
        }
        if (i == 6)
        {
          strcpy(o7, object_get_name(game_get_object(game, i))); /*copies in o7 the name of the object 3*/
        }
        if (i == 7)
        {
          strcpy(o8, object_get_name(game_get_object(game, i))); /*copies in o8 the name of the object 4*/
        }
        if (i == 8)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o9, object_get_name(game_get_object(game, i))); /*copies in o9 the name of the object 1*/
        }
        if (i == 9)
        {
          strcpy(o10, object_get_name(game_get_object(game, i))); /*copies in o10 the name of the object 2*/
        }
        if (i == 10)
        {
          strcpy(o11, object_get_name(game_get_object(game, i))); /*copies in o11 the name of the object 3*/
        }
        if (i == 11)
        {
          strcpy(o12, object_get_name(game_get_object(game, i))); /*copies in o12 the name of the object 4*/
        }
        if (i == 12)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o13, object_get_name(game_get_object(game, i))); /*copies in o13 the name of the object 1*/
        }
        if (i == 13)
        {
          strcpy(o14, object_get_name(game_get_object(game, i))); /*copies in o14 the name of the object 2*/
        }
        if (i == 14)
        {
          strcpy(o15, object_get_name(game_get_object(game, i))); /*copies in o15 the name of the object 3*/
        }
        if (i == 15)
        {
          strcpy(o16, object_get_name(game_get_object(game, i))); /*copies in o16 the name of the object 4*/
        }
        if (i == 16)
        {                                                        /*if the position of the array is 0, which means that we are in the first object*/
          strcpy(o17, object_get_name(game_get_object(game, i))); /*copies in o17 the name of the object 1*/
        }
        if (i == 17)
        {
          strcpy(o18, object_get_name(game_get_object(game, i))); /*copies in o18 the name of the object 2*/
        }
        if (i == 18)
        {
          strcpy(o19, object_get_name(game_get_object(game, i))); /*copies in o19 the name of the object 3*/
        }
        if (i == 19)
        {
          strcpy(o20, object_get_name(game_get_object(game, i))); /*copies in o20 the name of the object 4*/
        }
      }
    }

    if (id_next != NO_ID)
    {
      if (id_act != 14)
      {
        if (game_get_connection_status(game, space_get_id(space_act), S) == OPEN)
        {
          sprintf(str, "                      v");
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "                    -");
          screen_area_puts(ge->map, str);
        }

        sprintf(str, "              +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "              |            %2d|", (int)id_next);
        screen_area_puts(ge->map, str);
        sprintf(str, "              |%s      |   ", space_get_gdesc(game_get_space(game, id_next), 0));
        screen_area_puts(ge->map, str);
        sprintf(str, "              |%s      |   ", space_get_gdesc(game_get_space(game, id_next), 1));
        screen_area_puts(ge->map, str);
        sprintf(str, "              |%s      |   ", space_get_gdesc(game_get_space(game, id_next), 2));
        screen_area_puts(ge->map, str);
      }
      else if (id_act == 14)
      {
        if (game_get_connection_status(game, space_get_id(space_act), S) == OPEN)
        {
          sprintf(str, "                             v");
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "        -");
          screen_area_puts(ge->map, str);
        }

        sprintf(str, "                      +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                      |             %2d|   ", (int)id_next);
        screen_area_puts(ge->map, str);
        sprintf(str, "                      |                |   ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                      |                |   ");
        screen_area_puts(ge->map, str);
      }
    }
    else
    {
      if (id_act != 14)
      {
        if (game_get_connection_status(game, space_get_id(space_act), S) == OPEN)
        {
          sprintf(str, "                    ");
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "                    ");
          screen_area_puts(ge->map, str);
        }

        sprintf(str, "              ");
        screen_area_puts(ge->map, str);
        sprintf(str, "             ");
        screen_area_puts(ge->map, str);
        sprintf(str, "             ");
        screen_area_puts(ge->map, str);
        sprintf(str, "             ");
        screen_area_puts(ge->map, str);
        sprintf(str, "             ");
        screen_area_puts(ge->map, str);
      }
      else if (id_act == 14)
      {
        if (game_get_connection_status(game, space_get_id(space_act), S) == OPEN)
        {
          sprintf(str, "                             ");
          screen_area_puts(ge->map, str);
        }
        else
        {
          sprintf(str, "        ");
          screen_area_puts(ge->map, str);
        }

        sprintf(str, "                     ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                     ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                     ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                     ");
        screen_area_puts(ge->map, str);
      }
    }
  }

  /* Paint in the description area */

  screen_area_clear(ge->descript);
  sprintf(str, " Objects locations:");
  screen_area_puts(ge->descript, str); /*actualices the screen*/
  for (j = 0, str[0] = '\0'; j < 4; j++)
  {
    object_loc = game_get_object_location(game, object_get_id(game_get_object(game, j)));
    if (object_loc != NO_ID)
    {
      sprintf(str, "  %s:%ld", object_get_name(game_get_object(game, j)), object_loc);
      screen_area_puts(ge->descript, str);
    }
  }

  /*Paints if the player has an object in the pocket*/
  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);
  if ((player_loc = game_get_player_location(game)) != NO_ID)
  {
    sprintf(str, " Player location:%d", (int)player_loc);
    screen_area_puts(ge->descript, str);
  }

  if (player_inventory_is_empty(game_get_player(game)) != TRUE)
  {
    sprintf(str, " Player inventory (MAX %d): ", player_get_max_inv(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    for (j = 0; j < player_get_max_inv(game_get_player(game)); j++)
    {
      if (player_get_x_object(game_get_player(game), j) != NO_ID)
      {
        sprintf(str, "   %s ", game_get_player_object_name_by_id(game, player_get_x_object(game_get_player(game), j)));
        screen_area_puts(ge->descript, str);
      }
    }
  }
  else
  {
    sprintf(str, " Player inventory (MAX %d): ", player_get_max_inv(game_get_player(game)));
    /*if the player has no object prints NO_ID*/
    screen_area_puts(ge->descript, str);
    sprintf(str, "  Empty");
    screen_area_puts(ge->descript, str);
  }

  if (game_get_player_health(game) > 0)
  {
    sprintf(str, " Player health:%d", (int)game_get_player_health(game));
    screen_area_puts(ge->descript, str);
  }

  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);
  if ((enem_loc = game_get_enemy_location(game)) != NO_ID)
  {
    sprintf(str, " Enemy location:%d", (int)enem_loc);
    screen_area_puts(ge->descript, str);
  }

  if (game_get_enemy_health(game) > 0)
  {
    sprintf(str, " Enemy health:%d", (int)game_get_enemy_health(game));
    screen_area_puts(ge->descript, str);
  }

  game_set_description(game, space_get_description(game_get_space(game, game_get_player_location(game))));

  sprintf(str, "  ");
  screen_area_puts(ge->descript, str);

  strcpy(descr, game_get_description(game));
  strcpy(illudescr, game_get_illudescription(game));
  if (descr != '\0')
  {
    sprintf(str, " Descriptions:");
    screen_area_puts(ge->descript, str);
    sprintf(str, "  %s", game_get_description(game));
    screen_area_puts(ge->descript, str);
  }
  if (illudescr != '\0')
  {
    sprintf(str, "  %s", illudescr);
    screen_area_puts(ge->descript, str);
  }
  /* Paint in the banner area */
  screen_area_puts(ge->banner, "  Halfonso la foca ");

  /* Paint in the help area */
  screen_area_clear(ge->help);

  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "    move or m, take or t, drop or d, attack or a, open or o, turnon or ton, turnoff or toff, inspect or i, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  statuslc = game_get_last_command_status(game);

  log = fopen(arch, "a");

  if (statuslc == OK)
  {
    sprintf(str, " %s (%s) : OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    fprintf(log, " %s (%s) : OK\n", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }
  else
  {
    sprintf(str, " %s (%s) : ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    fprintf(log, " %s (%s) : ERROR\n", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }
  fclose(log);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
