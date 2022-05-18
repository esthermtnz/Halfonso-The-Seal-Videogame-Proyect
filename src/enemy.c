/** 
 * @brief It implements the enemy module
 * 
 * @file enemy.c
 * @author Pablo Vargas
 * @version 2.0 
 * @date 28-2-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "enemy.h"

/**
 * @brief Structure with all the parameters of the enemy
 */
struct _Enemy {
    Id id; /*!< Enemy Id */
    char name[WORD_SIZE + 1]; /*!< Enemy name */
    Id location; /*!< Enemy location */
    int health; /*!< Enemy health */
};

/*It creates a new enemy and allocates memory for it*/

Enemy* enemy_create(Id id)
{
    Enemy *newEnemy = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }
    newEnemy = (Enemy *) malloc(sizeof(Enemy));
    if (newEnemy == NULL)
    {
        return NULL;
    }
    
    newEnemy->id = id;
    newEnemy->name[0] = '\0';
    newEnemy->location = NO_ID;
    newEnemy->health = 10;

    return newEnemy;
    
}

/*Destroys the enemy and frees its memory*/

STATUS enemy_destroy(Enemy* enemy)
{
    if (!enemy)
    {
        return ERROR;
    }
    
    free(enemy);
    enemy = NULL;
    return OK;
}

/*It gets the id of the enemy*/

Id enemy_get_id(Enemy* enemy)
{
    if (!enemy)
    {
        return NO_ID;
    }
    return enemy->id;
}

/*It sets the name of the enemy*/

STATUS enemy_set_name(Enemy* enemy, char* name)
{
    if (!enemy || !name)
    {
        return ERROR;
    }

    if (!strcpy(enemy->name, name))
    {
        return ERROR;
    }
    return OK;
    
}

/*It gets the name of the enemy*/

const char * enemy_get_name(Enemy* enemy)
{
    if (!enemy)
    {
        return NULL;
    }
    return enemy->name;
}

/*It sets the location of the enemy*/

STATUS enemy_set_location(Enemy* enemy, Id id)
{
    if (!enemy)
    {
        return ERROR;
    }
    enemy->location = id;
    return OK;
}

/*It gets the location of the enemy*/

Id enemy_get_location(Enemy* enemy)
{
    if (!enemy)
    {
        return FALSE;
    }
    return enemy->location;
}

/*It sets the health of the enemy*/

STATUS enemy_set_health(Enemy* enemy, int health)
{
    if (!enemy)
    {
        return ERROR;
    }
    enemy->health = health;
    return OK;
}

/*It gets the health of the enemy*/

int enemy_get_health(Enemy* enemy)
{
    if (!enemy)
    {
        return 0;
    }
    return enemy->health;
}

/*it prints the enemy information*/

STATUS enemy_print(Enemy* enemy)
{
    if (!enemy)
    {
        return ERROR;
    }
    
    fprintf(stdout, "--> Enemy (Id: %ld; Name: %s ; Health: %d; Location: %ld)\n", enemy->id, enemy->name, enemy->health, enemy->location);
    return OK;
}
