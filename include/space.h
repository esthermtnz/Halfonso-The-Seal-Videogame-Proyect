/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
/**
 * @brief Space structure
 */
typedef struct _Space Space;
/**
 * @brief Max number of spaces
 */
#define MAX_SPACES 100
/**
 * @brief declaration of first space
 */
#define FIRST_SPACE 1

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space
  * @author Profesores PPROG
  *
  * space_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the description of a space
  * @author Esther Martinez
  * 
  * @param space a pointer to the space
  * @param description a string with the description to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_description(Space* space, char* description);

/**
  * @brief It gets the description of a space
  * @author Esther Martinez
  * 
  * @param space a pointer to the space
  * @return  a string with the description of the space
  */
const char* space_get_description(Space* space);

/**
  * @brief It sets the description of the illumination of a space
  * @author Esther Martinez
  * 
  * @param space a pointer to the space
  * @param illudescription a string with the description of the illumination of the space to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_illudescription(Space* space, char* illudescription);

/**
  * @brief It gets the description of the illumination of a space
  * @author Esther Martinez
  * 
  * @param space a pointer to the space
  * @return  a string with the description of the illumination of the space
  */
const char* space_get_illudescription(Space* space);

/**
  * @brief It adds an object into the space
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param id a pointer to the id
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @brief It deletes an object of the space
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param id a pointer to the id
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_del_object(Space* space, Id id);

/**
  * @brief It finds an object in the space
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param id a pointer to the id
  * @return TRUE, if it finds the object or FALSE if not
  */
BOOL space_find_object(Space* space, Id id);

/**
  * @brief It sets the gdesc
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param string pointer to string
  * @param pos the position
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_gdesc(Space* space, char* string, int pos);

/**
  * @brief It gets the gdesc
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param pos the position
  * @return type char
  */
char* space_get_gdesc(Space* space,int pos);

/**
  * @brief It gets the illumination
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @return TRUE if it is illuminated, else FALSE
  */
BOOL space_get_illumination(Space * space);

/**
  * @brief It sets the illumination
  * @author Esther Martinez
  *
  * @param space a pointer to the space
  * @param ilumination True if it is illuminated else False
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_illumination(Space *space, BOOL ilumination);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space and prints the objects.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

#endif
