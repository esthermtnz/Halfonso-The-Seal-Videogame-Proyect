/**
 * @brief It implements the object module
 *
 * @file player.c
 * @author Pablo Vargas
 * @version 2.0
 * @date 9-2-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "types.h"
#include "player.h"
/**
 * @brief Structure that stores all info related to a player
 */
struct _Player
{
    Id id;                    /*!< Id number of the player, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the player */
    Inventory *inv;                /*!< Player inventory */
    Id location;              /*!< Id number of the location of the player*/
    int health;               /*!< Health of the player*/
};

/* Creates a new player */

Player *player_create(Id id)
{
    Player *newPlayer = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }
    newPlayer = (Player *)malloc(sizeof(Player));
    if (newPlayer == NULL)
    {

        return NULL;
    }

    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->inv = inventory_create();
    newPlayer->location = NO_ID;
    newPlayer->health = 10;

    return newPlayer;
}

/* Destroys current player */

STATUS player_destroy(Player *player)
{
    if (!player)
    {
        return ERROR;
    }
    
    inventory_destroy(player->inv);
    free(player);
    
    player = NULL;
    return OK;
}

/* It gets the id of the player */

Id player_get_id(Player *player)
{
    if (!player)
    {
        return NO_ID;
    }
    return player->id;
}

/* It sets the id of a player */

STATUS player_set_name(Player *player, char *name)
{
    if (!player || !name)
    {
        return ERROR;
    }

    if (!strcpy(player->name, name))
    {
        return ERROR;
    }
    return OK;
}

/* It gets the name of the player */

const char *player_get_name(Player *player)
{
    if (!player)
    {
        return NULL;
    }
    return player->name;
}

/* It sets player's object id */

STATUS player_add_object(Player *player, Id value)
{
    if (!player || value == NO_ID)
    {
        return ERROR;
    }
    inventory_add_object(player->inv, value);
    return OK;
}

/* It gets returns the player's object */

STATUS player_delete_object(Player *player, Id id)
{
    if (!player || id == NO_ID)
    {
        return ERROR;
    }
    inventory_delete_object(player->inv, id);
    return OK;
}

STATUS player_set_max_inv(Player *player, int n)
{
    if (!player || n < 0)
    {
        return ERROR;
    }
    inventory_set_max_objs(player->inv, n);
    return OK;
}

int player_get_max_inv(Player *player)
{
    if (!player)
    {
        return -1;
    }
    return inventory_get_max_objs(player->inv);
}

BOOL player_isthere_object(Player *player, Id id)
{
    if (!player || id == NO_ID)
    {
        return FALSE;
    }
    return inventory_isthere_obj(player->inv, id);
}

BOOL player_inventory_is_full(Player *player)
{
    if (player == NULL)
    {
        return FALSE;
    }
    return inventory_is_full(player->inv);
}

BOOL player_inventory_is_empty(Player *player)
{
    if (player == NULL)
    {
        return FALSE;
    }
    return inventory_is_empty(player->inv);
}
/* It sets the player's location */

STATUS player_set_location(Player *player, Id id)
{
    if (!player)
    {
        return ERROR;
    }
    player->location = id;
    return OK;
}

/* It gets the location of the player */

Id player_get_location(Player *player)
{
    if (!player)
    {
        return FALSE;
    }
    return player->location;
}

/* Sets the health of the player */

STATUS player_set_health(Player *player, int health)
{
    if (!player)
    {
        return ERROR;
    }
    player->health = health;
    return OK;
}
/* Gets the health of the player */
int player_get_health(Player *player)
{
    if (!player)
    {
        return ERROR;
    }
    return player->health;
}


STATUS player_print(Player *player)
{

    /* Error Control */
    if (!player || player->inv == ERROR)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the space */
    fprintf(stdout, "--> Player (Id: %ld; Name: %s ; Health: %d; Location: %ld)\n", player->id, player->name, player->health, player->location);

    /* 2. Print if there is an object in the space or not */
    fprintf(stdout, "--> Current inventory: \n");
    inventory_print(player->inv);
    return OK;
}

Id player_get_x_object(Player *player, int i)
{
	if (player == NULL || i < 0 || i > inventory_get_max_objs(player->inv))
	{
		return NO_ID;
	}
	return inventory_get_x_id(player->inv, i);
}
