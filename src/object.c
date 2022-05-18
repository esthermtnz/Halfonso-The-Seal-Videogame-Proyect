/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Esther Martinez
 * @version 2.0
 * @date 9-2-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Structure that stores all the information of object
 */

struct _Object
{
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
  char description [WORD_SIZE +1 ]; /*!< Description of the object */
  BOOL movable;
  Id dependency;
  Id open;
  BOOL illuminate;
  BOOL turnedon;
};

/** object_create allocates memory for a new object
 *  and initializes its members
 */
Object *object_create(Id id)
{
  Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *)malloc(sizeof(Object));
  if (newObject == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->description[0] = '\0';
  newObject->movable = FALSE;
  newObject->dependency = NO_ID;
  newObject->open = NO_ID;
  newObject->illuminate = FALSE;
  newObject->turnedon = FALSE;
  return newObject;
}

/** object_destroy frees the previous memory allocation
 *  for an object
 */
STATUS object_destroy(Object *object)
{
  if (!object)
  {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

/** It gets the id of an object
 */
Id object_get_id(Object *object)
{
  if (!object)
  {
    return NO_ID;
  }
  return object->id;
}

/** It sets the name of an object
 */
STATUS object_set_name(Object *object, char *name)
{
  if (!object || !name)
  {
    return ERROR;
  }

  if (!strcpy(object->name, name))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the name of an object
 */
const char *object_get_name(Object *object)
{
  if (!object)
  {
    return NULL;
  }
  return object->name;
}

/** It sets the description of an object
 */
STATUS object_set_description(Object *object, char *description)
{
  if (!object || !description)
  {
    return ERROR;
  }

  if (!strcpy(object->description, description))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the description of an object
 */
const char *object_get_description(Object *object)
{
  if (!object)
  {
    return NULL;
  }
  return object->description;
}

/** It prints the object information
 */
STATUS object_print(Object *object)
{

  /* Error Control */
  if (!object)
  {
    return ERROR;
  }

  /*  Print the id and the name of the object */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s, Description: %s\n)", object->id, object->name, object->description);

  return OK;
}

BOOL object_get_movable(Object *object)
{
	if(object == NULL)
	{
		return FALSE;
	}
	return object->movable;
}

STATUS object_set_movable(Object *object, BOOL value)
{
	if(object == NULL)
	{
		return ERROR;
	}
	object->movable = value;
	return OK;
}

Id object_get_dependency(Object *object)
{
	if(object == NULL)
	{
		return NO_ID;
	}
	return object->dependency;
}

STATUS object_set_dependency(Object *object, Id id)
{
	if(object == NULL || id == NO_ID)
	{
		return ERROR;
	}
	object->dependency = id;
	return OK;
}

Id object_get_open(Object *object)
{
	if(object == NULL)
	{
		return NO_ID;
	}
	return object->open;
}

STATUS object_set_open(Object *object, Id id)
{
	if(object == NULL || id == NO_ID)
	{
		return ERROR;
	}
	object->open = id;
	return OK;
}

BOOL object_get_illuminate(Object *object)
{
	if(object == NULL)
	{
		return FALSE;
	}
	return object->illuminate;
}

STATUS object_set_illuminate(Object *object, BOOL value)
{
	if(object == NULL)
	{
		return ERROR;
	}
	object->illuminate = value;
	return OK;
}

BOOL object_get_turnedon(Object *object)
{
	if(object == NULL)
	{
		return FALSE;
	}
	return object->turnedon;
}

STATUS object_set_turnedon(Object *object,BOOL value)
{
	if(object == NULL)
	{
		return ERROR;
	}
	object->turnedon = value;
	
	return OK;
}

