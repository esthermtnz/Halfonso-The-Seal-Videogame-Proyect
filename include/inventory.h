/**
 * @brief Define al modulo inventory
 *
 * @file inventory.h
 * @author Jaime Sanchez Esteban
 * @version 1.0
 * @date 22-3-2022
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

/**
  * @brief Declaration of structure Inventory
  */
typedef struct _Inventory Inventory;

/**
  * @brief Crea e inicializa un inventario
  * @author Jaime Sanchez Esteban
  *
  * @return Devuelve el inventario nuevo o NULL en caso de error
  */
Inventory *inventory_create();

/**
  * @brief Elimina el inventario solicitado
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario que se va a eliminar
  * @return Devuelve OK si todo va bien o ERROR en caso contrario
  */
STATUS inventory_destroy(Inventory *inv);

/**
  * @brief Agrega un objeto a un inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario al que se le va a agregar un objeto
  * @param id Es la id del objeto que se va a agregar al inventario
  * @return Devuelve OK si todo va bien o ERROR en caso de error o de que el inventario este lleno
  */
STATUS inventory_add_object(Inventory *inv, Id id);

/**
  * @brief Elimina el objeto solicitado del inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario del que se va a eliminar un objeto
  * @param id Es la id del objeto que se quiere eliminar
  * @return Devuelve OK si todo va bien o ERROR en caso de error o de que el inventario este vacio
  */
STATUS inventory_delete_object(Inventory *inv, Id id);

/**
  * @brief Busca si existe un objeto en el inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario en el que se va a buscar el objeto
  * @param id Es la id del objeto que se quiere comprobar
  * @return Devuelve TRUE si el objeto existe y FALSE en caso contrario
  */
BOOL inventory_isthere_obj(Inventory *inv, Id id);

/**
  * @brief Establece una dimension maxima para el inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario al que se le va a asignar la dimension
  * @param objs Es el tamano que se va a asignar al inventario
  * @return Devuelve OK si todo va bien o ERROR si hay algun problema
  */
STATUS inventory_set_max_objs(Inventory *inv, int objs);

/**
  * @brief Obtiene la dimension maxima del inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario del que se quiere la dimension
  * @return Debuelve el tamano del inventario o -1 en caso de error
  */
int inventory_get_max_objs(Inventory *inv);

/**
  * @brief Comprueba si el inventario esta lleno o no
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario que se va a examinar
  * @return TRUE si el inventario esta lleno y FALSE si no lo esta
  */
BOOL inventory_is_full(Inventory *inv);

/**
  * @brief Comprueba si el inventario esta vacio o no
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario que se va a examinar
  * @return TRUE si el inventario esta vacio y FALSE si no lo esta
  */
BOOL inventory_is_empty(Inventory *inv);

/**
  * @brief Imprime por pantalla la informacion del inventario solicitado
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario a imprimir
  * @return Devuelve OK en caso de exito y ERROR en caso de error
  */
STATUS inventory_print(Inventory *inv);

/**
  * @brief Obtiene el contenido en una determinada posicion i del inventario
  * @author Jaime Sanchez Esteban
  *
  * @param inv Es el inventario al que se le va a asignar la dimension
  * @param i Ubicación de la id dentro del inventario
  * @return Devuelve la id solicitada o NO_ID en caso de error
  */
Id inventory_get_x_id(Inventory *inv, int i);
#endif
