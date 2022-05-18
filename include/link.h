/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Esther Martinez
 * @version 2.0
 * @date 21/3/22
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link;

/**
 * @brief It creates a new link
 * @author Esther Martinez
 *
 * link_create allocates memory for a new link
 *  and initializes its members
 * @param id the identification number for the new link
 * @return a new link, initialized
 */
Link *link_create(Id id);

/**
 * @brief It destroys a link
 * @author Esther Martinez
 *
 * link_destroy frees the previous memory allocation
 *  for a link
 * @param link a pointer to the link that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_destroy(Link *link);

/**
 * @brief It gets the id of a link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return the id of link
 */
Id link_get_id(Link *link);

/**
 * @brief It sets the name of a link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_name(Link *link, char *name);

/**
 * @brief It gets the name of a link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return  a string with the name of the link
 */
const char *link_get_name(Link *link);

/**
 * @brief It gets the id of the origin
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return the id number of the origin
 */
Id link_get_origin(Link *link);

/**
 * @brief It sets the id of the origin
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @param id the id number of the origin
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_origin(Link *link, Id id);

/**
 * @brief It gets the id of the destination
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return the id number of the destination
 */
Id link_get_destination(Link *link);

/**
 * @brief It sets the id of the destination
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @param id the id number of the destination
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_destination(Link *link, Id id);

/**
 * @brief It gets the direction of the link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return the direction of the link
 */
DIRECTION link_get_direction(Link *link);

/**
 * @brief It sets the direction of the link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @param direction the direction of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_direction(Link *link, DIRECTION direction);

/**
 * @brief It gets the status of the link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @return the status of the link
 */
LINKST link_get_status(Link *link);

/**
 * @brief It sets the status of the link
 * @author Esther Martinez
 *
 * @param link a pointer to the link
 * @param status the status of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_status(Link *link, LINKST status);

/**
 * @brief It prints the link information
 * @author Esther Martinez
 *
 * This function shows the id and name of the link, the origin, destination and direction.
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_print(Link *link);

#endif