/**
 * @brief It defines the enemy functionality
 *
 * @file enemy.h
 * @author Pablo Vargas
 * @version 1.0
 * @date 28-2-2022
 * @copyright GNU Public License
 */

#ifndef ENEMY_H
#define ENEMY_H
#include "types.h"
/**
  * @brief Enemy struct
  */
typedef struct _Enemy Enemy;

/**
  * @brief It creates a new enemy
  * @author Pablo Vargas
  *
  * enemy_create allocates memory for a new enemy
  *  and initializes its members
  * @param id the identification number for the new enemy
  * @return a new enemy, initialized
  */
Enemy* enemy_create(Id id);


/**
  * @brief It destroys the enemy
  * @author Pablo Vargas
  *
  * enemy_destroy frees the previous memory allocation 
  *  for the enemy
  * @param enemy a pointer to the enemy that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_destroy(Enemy* enemy);



/**
  * @brief It gets the id of the enemy
  * @author Pablo Vargas
  * 
  * @param enemy a pointer to the enemy
  * @return the id of an enemy
  */
Id enemy_get_id(Enemy* enemy);



/**
  * @brief It sets the name of an enemy
  * @author Pablo Vargas
  * 
  * @param enemy a pointer to the enemy
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_name(Enemy* enemy, char* name);


/**
  * @brief It gets the name of an enemy
  * @author Pablo Vargas
  * 
  * @param enemy a pointer to the enemy
  * @return  a string with the name of the enemy
  */
const char * enemy_get_name(Enemy* enemy);


/**
  * @brief It sets the enemy location
  * @author Pablo Vargas
  *
  * This function sets the enemy's location of a one given as an argument.
  * @param enemy a pointer to the enemy
  * @param id of an id
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_set_location(Enemy* enemy, Id id);


/**
  * @brief It gets the enemy location
  * @author Pablo Vargas
  *
  * This function shows the enemy's location.
  * @param enemy a pointer to the enemy
  * @return the enemy location in id format
  */
Id enemy_get_location(Enemy* enemy);


/**
  * @brief It sets the enemy health
  * @author Pablo Vargas
  *
  * This function sets the enemy's health.
  * @param enemy a pointer to the enemy
  * @param health desired health to set
  * @return Ok if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_set_health(Enemy* enemy, int health);


/**
  * @brief It gets the enemy health
  * @author Pablo Vargas
  *
  * This function shows the enemy's health.
  * @param enemy a pointer to the enemy
  * @return the enemy health in id format
  */
int enemy_get_health(Enemy* enemy);


/**
  * @brief It prints the enemy information
  * @author Pablo Vargas
  *
  * This function shows the id and name of the enemy.
  * @param enemy a pointer to the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_print(Enemy* enemy);
#endif
