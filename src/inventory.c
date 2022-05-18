/*
MODULO Inventory // Disenado por Jaime Sanchez Esteban
Modulo que permite el almacenamiento y gestion de objetos en un inventario que almacena un numero maximo de objetos determinado por MAX_INV
*/
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "set.h"
/**
 * @brief Structure with the parameters needed to contain a inventory
 */
struct _Inventory
{
	Set *objs; /*!< Set pointer with the ids of the objects*/
	int max_objs; /*!< Maximum capacity of the inventory*/
};

Inventory *inventory_create()
{
	Inventory *new_inventory;
	new_inventory = (Inventory *)malloc(sizeof(Inventory));
	if(new_inventory == NULL)
	{
		return NULL;
	}
	new_inventory->objs = set_create();
	new_inventory->max_objs = 0;
	return new_inventory;
}

STATUS inventory_destroy(Inventory *inv)
{
	if (inv == NULL)
	{
		return ERROR;
	}
	set_destroy(inv->objs);
	free(inv);
	return OK;
}

STATUS inventory_add_object(Inventory *inv, Id id)
{
	if (inv == NULL || id == NO_ID || inventory_is_full(inv) == TRUE)
	{
		return ERROR;
	}
	return set_add_object(inv->objs, id);
}

STATUS inventory_delete_object(Inventory *inv, Id id)
{
    if (inv == NULL || id == NO_ID || inventory_is_empty(inv) == TRUE)
    {
    	return ERROR;
    }
    return set_del_object(inv->objs, id);
}

BOOL inventory_isthere_obj(Inventory *inv, Id id)
{
	if (inv == NULL || id == NO_ID || inventory_is_empty(inv) == TRUE)
	{
		return FALSE;
	}
	if (set_find_object(inv->objs, id) == FALSE)
	{
		return FALSE;
	}
	return OK;
}

STATUS inventory_set_max_objs(Inventory *inv, int objs)
{
	if (inv == NULL || objs < 0)
	{
		return ERROR;
	}
	inv->max_objs = objs;
	return OK;
}

int inventory_get_max_objs(Inventory *inv)
{
	if (inv == NULL)
	{
		return -1;
	}
	return inv->max_objs;
}

BOOL inventory_is_full(Inventory *inv)
{
	if(inv == NULL)
	{
		return FALSE;
	}
	if (set_get_n_ids(inv->objs) == inv->max_objs)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL inventory_is_empty(Inventory *inv)
{
	if(inv == NULL)
	{
		return FALSE;
	}
	if (set_get_n_ids(inv->objs) == 0)
	{
		return TRUE;
	}
	return FALSE;
}

STATUS inventory_print(Inventory *inv)
{
	if (inv == NULL)
	{
		return ERROR;
	}
	fprintf(stdout, "Objects in the inventory:\n");
	if(set_print(inv->objs)== ERROR)
	{
		return ERROR;
	}
	fprintf(stdout, "Inventory Capacity: %d\n", inv->max_objs);
	return OK;
}

Id inventory_get_x_id(Inventory *inv, int i)
{
	if (inv == NULL)
	{
		return NO_ID;
	}
	return set_get_x_id(inv->objs, i);
}
