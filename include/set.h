/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Esther Martinez
 * @version 2.0
 * @date 26-2-2022
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h" /*Macros for the ids included in types*/
/**
 * @brief Set structure
 */
typedef struct _Set Set;

/**
 * @brief It creates a new set
 * @author Esther Martinez
 *
 * set_create allocates memory for the ids
 *  and initializes its members
 * @return a new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys the set
 * @author Esther Martinez
 *
 * set_destroy frees the previous memory allocation
 *  for the array of ids
 * @param set a pointer to the set that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_destroy(Set *set);

/**
 * @brief It adds a new object to the set
 * @author Esther Martinez
 *
 * This function adds a new object to the set
 * @param set a pointer to the set
 * @param id a pointer to the object's id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_add_object(Set *set, Id id);

/**
 * @brief It deletes an object of the set
 * @author Esther Martinez
 *
 * This function deletes an object given as an argument to the set
 * @param set a pointer to the set
 * @param id a pointer to the object's id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_del_object(Set *set, Id id);

/**
 * @brief Finds object's id
 * @author Esther Martinez
 *
 * This function finds a certain object in the set
 * @param set a pointer to the set
 * @param id a pointer to the object's id
 * @return TRUE, if it finds the object or FALSE if not
 */
BOOL set_find_object(Set *set, Id id);

/**
 * @brief It prints the set information
 * @author Esther Martinez
 *
 * This function shows the all the ids contained in the array.
 * @param set a pointer to the set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_print(Set *set);

/**
 * @brief It returns the number of ids currently in the set
 * @author Jaime Sanchez Esteban
 *
 * This function shows the all the ids contained in the array.
 * @param s a pointer to the set
 * @return The number of ids of the set of -1 in case of error
 */
int set_get_n_ids(Set *s);

/**
 * @brief It returns the id of an object from a certain position
 * @author Jaime Sanchez Esteban
 *
 * @param set a pointer to the set
 * @param i location of the object
 * @return The id of the object or NO_ID in case of error
 */
Id set_get_x_id(Set *set, int i);
#endif
