/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Esther Martinez
 * @version 2.0
 * @date 26-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**
 * @brief Structure with the capacity to store a certain number of Ids
 */
struct _Set
{
  Id ids[MAX_ID]; /*!< Array of ids */
  int n_ids;      /*!< Number of objects*/
};

/** set_create allocates memory for the array of ids
 *  and initializes its members
 */
Set *set_create()
{
  int i;
  Set *newSet = NULL;

  /* Error control */
  if (newSet != NULL)
    return NULL;

  newSet = (Set *)malloc(sizeof(Set));
  if (newSet == NULL)
  {
    return NULL;
  }

  /* Initialization of the array*/
  for (i = 0; i < MAX_ID; i++)
  {
    newSet->ids[i] = NO_ID;
  }
  newSet->n_ids = 0;
  return newSet;
}

/** set_destroy frees the previous memory allocation
 *  for the array of ids.
 */
STATUS set_destroy(Set *set)
{
  if (!set)
  {
    return ERROR;
  }

  free(set);
  set = NULL;
  return OK;
}

/** It adds a new object to the set
 */
STATUS set_add_object(Set *set, Id id)
{

  if (!set || id == NO_ID)
  {
    return ERROR;
  }

  if (set->n_ids < MAX_ID)
  {
    set->ids[set->n_ids] = id;
    set->n_ids++;
    return OK;
  }
  else
  {
    return ERROR;
  }
}

/** It deletes an object of the set
 */
STATUS set_del_object(Set *set, Id id)
{
  int i;

  if (!set || id == NO_ID)
  {
    return ERROR;
  }

  for (i = 0; i < set->n_ids; i++)
  {
    if (set->ids[i] == id)
    {
      set->ids[i] = NO_ID;
      set->ids[i] = set->ids[set->n_ids - 1];
      set->n_ids--;
      return OK;
    }
  }

  return ERROR;
}

/** It finds an object in the set
 */
BOOL set_find_object(Set *set, Id id)
{
  int i;

  if (!set || id == NO_ID)
  {
    return FALSE;
  }

  for (i = 0; i < set->n_ids; i++)
  {
    if (set->ids[i] == id)
    {
      return TRUE;
    }
  }
  return FALSE;
}

/** It prints the set information
 */
STATUS set_print(Set *set)
{
  int i;

  /* Error Control */
  if (!set)
  {
    return ERROR;
  }

  /*  Print the number of ids in the set */
  fprintf(stdout, "--> Set (Number of objects: %d)\n", set->n_ids);

  /*Prints each id*/
  for (i = 0; i < MAX_ID; i++)
  {
    if (set->ids[i] == !NO_ID)
    {
      fprintf(stdout, "--> Id: %ld\n", set->ids[i]);
    }
  }
  return OK;
}

int set_get_n_ids(Set *s)
{
	if(s == NULL)
	{
		return -1;
	}
	return s->n_ids;
}

Id set_get_x_id(Set *set, int i)
{
	if (set == NULL)
	{
		return NO_ID;
	}
	return set->ids[i];
}
