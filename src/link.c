/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Esther Martinez
 * @version 2.0
 * @date 21/3/22
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

/**
 * @brief Structure that stores all the information of the link
 *
 */
struct _Link
{
  Id id;                    /*!< Id number of the links, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id origin;                /*!< Id number of the origin space*/
  Id destination;           /*!< Id number of the destination space*/
  DIRECTION direction;      /*!< direction can be north, south, east, west, up and down*/
  LINKST status;            /*!< Status of the link , OPEN or CLOSE*/
};

Link *link_create(Id id)
{
  Link *newLink = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newLink = (Link *)malloc(sizeof(Link));
  if (newLink == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty link*/
  newLink->id = id;
  newLink->name[0] = '\0';
  newLink->origin = NO_ID;
  newLink->destination = NO_ID;
  newLink->direction = N;
  newLink->status = CLOSE;

  return newLink;
}

STATUS link_destroy(Link *link)
{
  if (!link)
  {
    return ERROR;
  }

  free(link);
  link = NULL;
  return OK;
}

/** It gets the id of a link
 */
Id link_get_id(Link *link)
{
  if (!link)
  {
    return NO_ID;
  }
  return link->id;
}

/** It sets the name of a link
 */
STATUS link_set_name(Link *link, char *name)
{
  if (!link || !name)
  {
    return ERROR;
  }

  if (!strcpy(link->name, name))
  {
    return ERROR;
  }
  return OK;
}
/** It gets the name of a link
 */
const char *link_get_name(Link *link)
{
  if (!link)
  {
    return NULL;
  }
  return link->name;
}

/** It gets the id of the origin
 */
Id link_get_origin(Link *link)
{
  if (!link)
  {
    return NO_ID;
  }
  return link->origin;
}

/** It sets the id of the origin
 */
STATUS link_set_origin(Link *link, Id id)
{
  if (!link || id == NO_ID)
  {
    return ERROR;
  }
  link->origin = id;
  return OK;
}

/** It gets the id of the destination
 */
Id link_get_destination(Link *link)
{
  if (!link)
  {
    return NO_ID;
  }
  return link->destination;
}

/** It sets the id of the destination
 */
STATUS link_set_destination(Link *link, Id id)
{
  if (!link || id == NO_ID)
  {
    return ERROR;
  }
  link->destination = id;
  return OK;
}

/** It gets the direction of the link
 */
DIRECTION link_get_direction(Link *link)
{

  if (!link)
  {
    return N;
  }
  return link->direction;
}
/** It sets the direction of the link
 */
STATUS link_set_direction(Link *link, DIRECTION direction)
{

  if (!link)
  {
    return ERROR;
  }

  link->direction = direction;
  return OK;
}

/** It gets the status of the link
 */
LINKST link_get_status(Link *link)
{
  if (!link)
  {
    return CLOSE;
  }

  return link->status;
}

/** It sets the status of the link
 */
STATUS link_set_status(Link *link, LINKST status)
{
  if (!link)
  {
    return ERROR;
  }

  link->status = status;
  return OK;
}

STATUS link_print(Link *link)
{

  /* Error Control */
  if (!link)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the link */

  if (link_get_status(link) == OPEN)
  {
    fprintf(stdout, "--> Link (Id: %ld; Name: %s, Status: OPEN)\n", link->id, link->name);
  }
  else
  {
    fprintf(stdout, "--> Link (Id: %ld; Name: %s, Status: CLOSE)\n", link->id, link->name);
  }
  /* 2. For each direction, print its link */

  switch (link_get_direction(link))
  {

    {
    case N:
      fprintf(stdout, "---> North link: %d.\n", link_get_direction(link));
      break;
    case S:
      fprintf(stdout, "---> South link: %d.\n", link_get_direction(link));
      break;
    case E:
      fprintf(stdout, "---> East link: %d.\n", link_get_direction(link));
      break;
    case W:
      fprintf(stdout, "---> West link: %d.\n", link_get_direction(link));
      break;
    case U:
      fprintf(stdout, "---> Up link: %d.\n", link_get_direction(link));
      break;
    case D:
      fprintf(stdout, "---> Down link: %d.\n", link_get_direction(link));
      break;
    default:
      fprintf(stdout, "---> No link.\n");
      break;
    }
  }

  return OK;
}
