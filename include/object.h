/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Esther Martinez
 * @version 2.0
 * @date 9-2-2022
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
 * @brief Structure of Object
 */
typedef struct _Object Object;

/**
 * @brief It creates a new object
 * @author Esther Martinez
 *
 * object_create allocates memory for a new object
 *  and initializes its members
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object *object_create(Id id);

/**
 * @brief It destroys an object
 * @author Esther Martinez
 *
 * object_destroy frees the previous memory allocation
 *  for an object
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_destroy(Object *object);

/**
 * @brief It gets the id of an object
 * @author Esther Martinez
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object *object);

/**
 * @brief It sets the name of an object
 * @author Esther Martinez
 *
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief It gets the name of an object
 * @author Esther Martinez
 *
 * @param object a pointer to the object
 * @return  a string with the name of the object
 */
const char *object_get_name(Object *object);

/**
 * @brief It sets the description of an object
 * @author Esther Martinez
 *
 * @param object a pointer to the object
 * @param description a string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_description(Object *object, char *description);

/**
 * @brief It gets the description of an object
 * @author Esther Martinez
 *
 * @param object a pointer to the object
 * @return  a string with the description of the object
 */
const char *object_get_description(Object *object);

/**
 * @brief It prints the object information
 * @author Esther Martinez
 *
 * This function shows the id and name of the object.
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_print(Object *object);

/**
 * @brief Devuelve si el objeto es movible o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @return TRUE en caso afirmativo y FALSE en caso contrario
 */
BOOL object_get_movable(Object *object);

/**
 * @brief Establece si el objeto se puede mover no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @param value valor a asignar
 * @return OK si todo va bien y ERROR en caso contrario
 */
STATUS object_set_movable(Object *object, BOOL value);

/**
 * @brief Devuelve si el objeto depende de otro o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @return La id del objeto del que depende o NO_ID si no depende de ninguno
 */
Id object_get_dependency(Object *object);

/**
 * @brief Establece si el objeto dependera de otro o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @param id id del valor del que dependera el objeto
 * @return OK si todo va bien y ERROR en caso contrario
 */
STATUS object_set_dependency(Object *object, Id id);

/**
 * @brief Devuelve la id del enlace que abre el objeto
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @return La id del link que abre o NO_ID si no abre ninguno
 */
Id object_get_open(Object *object);

/**
 * @brief Establece si el objeto abrira enlaces o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @param id id del enlace del que abrira el objeto
 * @return OK si todo va bien y ERROR en caso contrario
 */
STATUS object_set_open(Object *object, Id id);

/**
 * @brief Devuelve si el objeto ilumina o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @return TRUE en caso afirmativo y FALSE en caso contrario
 */
BOOL object_get_illuminate(Object *object);

/**
 * @brief Establece si el objeto puede iluminar o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @param value valor a asignar
 * @return OK si todo va bien y ERROR en caso contrario
 */
STATUS object_set_illuminate(Object *object, BOOL value);

/**
 * @brief Devuelve si el objeto esta encendido o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @return TRUE en caso afirmativo y FALSE en caso contrario
 */
BOOL object_get_turnedon(Object *object);

/**
 * @brief Establece si el objeto esta encendido o no
 * @author Jaime Sanchez Esteban
 *
 * @param object puntero al objeto
 * @param value valor a asignar
 * @return OK si todo va bien y ERROR en caso contrario
 */
STATUS object_set_turnedon(Object *object, BOOL value);

#endif
