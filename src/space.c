/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "set.h"
/**
 * @brief number of rows
 */
#define ROWS 5
/**
 * @brief number of cols
 */
#define COLS 9
/**
 * @brief Structure that stores all the information of a space.
 */
struct _Space
{
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Set *objects;             /*!< Whether the space has objects or not */
  char description[WORD_SIZE+1]; /*!< Description of the space */
  char illudescription[WORD_SIZE+1]; /*!< Description of the illumination of the space */
  char gdesc[ROWS][COLS+1];           /*!< Draws the anthill in the space*/
  BOOL illumination;          /*!< TRUE if it's illuminated , else FALSE*/
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->objects = set_create();
  newSpace->description[0] = '\0';
  newSpace->illudescription[0] = '\0';
  newSpace->illumination = FALSE;

  /* Initialization of gdesc*/
  for(i=0;i<ROWS;i++){
    newSpace->gdesc[i][0]= '\0';
  }

  return newSpace;
}

/** space_destroy frees the previous memory allocation
 *  for a space
 */
STATUS space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objects);

  free(space);
  space = NULL;
  return OK;
}

/** It gets the id of a space
 */
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
 */
STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the name of a space
 */
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/** It sets the description of a space
 */
STATUS space_set_description(Space *space, char *description)
{
  if (!space || !description)
  {
    return ERROR;
  }

  if (!strcpy(space->description, description))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the description of a space
 */
const char *space_get_description(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->description;
}

/** It sets the description of the illumination a space
 */
STATUS space_set_illudescription(Space *space, char *illudescription)
{
  if (!space || !illudescription)
  {
    return ERROR;
  }

  if (!strcpy(space->illudescription, illudescription))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the description of the illumination of a space
 */
const char *space_get_illudescription(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->illudescription;
}

/** It adds an object to space
 */
STATUS space_add_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  if (set_add_object(space->objects, id) == OK){
    return OK;
  } else{
    return ERROR;
  }
  return ERROR;
}

/** It deletes an object of the space
 */
STATUS space_del_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  if (set_del_object(space->objects, id)==OK){
    return OK;
  } else{
    return ERROR;
  }
  return ERROR;
}

/** It finds an object in the space
 */
BOOL space_find_object(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return FALSE;
  }

  if (set_find_object(space->objects, id) == TRUE)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

STATUS space_set_gdesc(Space* space, char* string, int position){
  if(!space||!string||position<0||position>ROWS){
    return ERROR;
  }

  if(strlen(string)== COLS){
    strcpy(space->gdesc[position],string);
    return OK;
  }

  return ERROR;
}

char* space_get_gdesc(Space* space,int position){
  if(!space||position<0||position> ROWS){
    return NULL;
  }

  return space->gdesc[position];
}

/** It gets the illumination of the space
 */
BOOL space_get_illumination(Space * space){
  if (!space)
  {
    return FALSE;
  }

  return space->illumination;
}

/** It sets the illumination of the space
 */
STATUS space_set_illumination(Space *space, BOOL illumination){
  if (!space)
  {
    return ERROR;
  }

  space->illumination = illumination;
  return OK;
}


/** It prints the space information
 */
STATUS space_print(Space *space)
{

  /* Error Control */
  if (!space)
  {
    return ERROR;
  }

  /* 1. Print the id,the name ,the description and the illumination of the space */

  fprintf(stdout, "--> Space (Id: %ld; Name: %s, Description: %s, Illumination: %d, IlluDescription: %s)\n", space->id, space->name, space->description,space->illumination, space->illudescription);
  

  /* 2. Print if there are objects in the space or not */

  fprintf(stdout, "---> Objectos: \n");
  set_print(space->objects);

  return OK;
}
