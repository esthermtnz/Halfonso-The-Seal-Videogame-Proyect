/**
 * @brief It tests player module
 *
 * @file player_test.c
 * @author Jaime Sanchez Esteban
 * @version 1.0
 * @date 05-04-2022
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "inventory.h"
#include "set.h"
#include "player_test.h"
#include "test.h"
/**
 * @brief Max number of tests
 */
#define MAX_TESTS 39

/**
 * @brief Main function for player unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv)
{
    int test = 0;
    int all =1;

    if (argc < 2)
    {
        printf("Running all test for module player:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test<1 && test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS); 
        }
    }

    if (all || test == 1)
    {
        test1_player_create();
    }
    if (all || test == 2)
    {
        test1_player_set_name();
    }
    if (all || test == 3)
    {
        test2_player_set_name();
    }
    if (all || test == 4)
    {
        test3_player_set_name();
    }
    if (all || test == 5)
    {
        test1_player_get_id();
    }
    if (all || test == 6)
    {
        test2_player_get_id();
    }
    if (all || test == 7)
    {
        test1_player_get_name();
    }
    if (all || test == 8)
    {
        test2_player_get_name();
    }
    if (all || test == 9)
    {
        test1_player_set_health();
    }
    if (all || test == 10)
    {
        test2_player_set_health();
    }
    if (all || test == 11)
    {
        test3_player_set_health();
    }
    if (all || test == 12)
    {
        test1_player_set_location();
    }
    if (all || test == 13)
    {
        test2_player_set_location();
    }
    if (all || test == 14)
    {
        test3_player_set_location();
    }
    if (all || test == 15)
    {
        test1_player_get_health();
    }
    if (all || test == 16)
    {
        test2_player_get_health();
    }
    if (all || test == 17)
    {
        test1_player_get_location();
    }
    if (all || test == 18)
    {
        test2_player_get_location();
    }
    if (all || test == 19)
    {
        test1_player_add_object();
    }
    if (all || test == 20)
    {
        test2_player_add_object();
    }
    if (all || test == 21)
    {
        test3_player_add_object();
    }
    if (all || test == 22)
    {
        test1_player_delete_object();
    }
    if (all || test == 23)
    {
        test2_player_delete_object();
    }
    if (all || test == 24)
    {
        test3_player_delete_object();
    }
    if (all || test == 25)
    {
        test1_player_set_max_inv();
    }
    if (all || test == 26)
    {
        test2_player_set_max_inv();
    }
    if (all || test == 27)
    {
        test3_player_set_max_inv();
    }
    if (all || test == 28)
    {
        test1_player_get_max_inv();
    }
    if (all || test == 29)
    {
        test2_player_get_max_inv();
    }
    if (all || test == 30)
    {
        test1_player_is_there_object();
    }
    if (all || test == 31)
    {
        test2_player_is_there_object();
    }
    if (all || test == 32)
    {
        test3_player_is_there_object();
    }
    if (all || test == 33)
    {
        test4_player_is_there_object();
    }
    if (all || test == 34)
    {
        test1_inventory_is_full();
    }
    if (all || test == 35)
    {
        test2_inventory_is_full();
    }
    if (all || test == 36)
    {
        test3_inventory_is_full();
    }
    if (all || test == 37)
    {
        test1_inventory_is_empty();
    }
    if (all || test == 38)
    {
        test2_inventory_is_empty();
    }
    if (all || test == 39)
    {
        test3_inventory_is_empty();
    }
    
    PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_player_create()
{
    int result;
    Player *e;
    e = player_create(5);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    player_destroy(e);
}

void test1_player_set_name()
{
    Player *e;
    e = player_create(5);
    PRINT_TEST_RESULT(player_set_name(e, "malo") == OK);
    player_destroy(e);
}


void test2_player_set_name()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_name(e, "malo") == ERROR);
}

void test3_player_set_name()
{
    Player *e;
    e = player_create(5);
    PRINT_TEST_RESULT(player_set_name(e, NULL) == ERROR);
    player_destroy(e);
}

void test1_player_get_name()
{
    Player *e;
    e = player_create(5);
    player_set_name(e, "adios");
    PRINT_TEST_RESULT(strcmp(player_get_name(e), "adios") == 0);
    player_destroy(e);
}

void test2_player_get_name()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_name(e) == NULL);
}


void test1_player_get_id()
{
    Player *e;
    e = player_create(5);
    PRINT_TEST_RESULT(player_get_id(e) == 5);
    player_destroy(e);
}

void test2_player_get_id()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_id(e) == NO_ID);
}

void test1_player_set_location()
{
    Player *e;
    e = player_create(5);
    PRINT_TEST_RESULT(player_set_location(e, 0) == OK);
    player_destroy(e);
}

void test2_player_set_location()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_location(e, 0) == ERROR);
}

void test3_player_set_location()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_location(e, NO_ID) == ERROR);
}

void test1_player_get_location()
{
    Player *e;
    e = player_create(5);
    player_set_location(e, 0);
    PRINT_TEST_RESULT(player_get_location(e) == 0);

    player_destroy(e);
}

void test2_player_get_location()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_location(e) == FALSE);
}

void test1_player_set_health()
{
    Player *e;
    e = player_create(5);
    PRINT_TEST_RESULT(player_set_health(e, 10) == OK);
    player_destroy(e);
}

void test2_player_set_health()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_health(e, 10) == ERROR);
}

void test3_player_set_health()
{
    Player *e=NULL;
    PRINT_TEST_RESULT(player_set_health(e, 0) == ERROR);
}

void test1_player_get_health()
{
    Player *e;
    e = player_create(5);
    player_set_health(e, 10);
    PRINT_TEST_RESULT(player_get_health(e) == 10);
    player_destroy(e);
}

void test2_player_get_health()
{
    Player *e=NULL;
    player_set_health(e, 10);
    PRINT_TEST_RESULT(player_get_health(e) == 0);
}

void test1_player_add_object()
{
	Player *e=NULL;
	e = player_create(1);
	PRINT_TEST_RESULT(player_add_object(e, 2) == OK);
	player_destroy(e);
}

void test2_player_add_object()
{
	Player *e=NULL;
	e = player_create(1);
	PRINT_TEST_RESULT(player_add_object(e, NO_ID) == ERROR);
	player_destroy(e);
}

void test3_player_add_object()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_add_object(e, 2) == ERROR);
}

void test1_player_delete_object()
{
	Player *e=NULL;
	e = player_create(1);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_delete_object(e, 2) == OK);
	player_destroy(e);
}

void test2_player_delete_object()
{
	Player *e=NULL;
	e = player_create(1);
	PRINT_TEST_RESULT(player_delete_object(e, NO_ID) == ERROR);
	player_destroy(e);
}

void test3_player_delete_object()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_delete_object(e, 2) == ERROR);
}

void test1_player_set_max_inv()
{
	Player *e=NULL;
	e = player_create(1);
	PRINT_TEST_RESULT(player_set_max_inv(e, 3) == OK);
	player_destroy(e);
}

void test2_player_set_max_inv()
{
	Player *e=NULL;
	e = player_create(1);
	PRINT_TEST_RESULT(player_set_max_inv(e, -1) == ERROR);
	player_destroy(e);
}

void test3_player_set_max_inv()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_set_max_inv(e, 1) == ERROR);
}

void test1_player_get_max_inv()
{
	Player *e=NULL;
	e = player_create(1);
	player_set_max_inv(e, 3);
	PRINT_TEST_RESULT(player_get_max_inv(e) == 3);
	player_destroy(e);
}

void test2_player_get_max_inv()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_get_max_inv(e) == -1);
}

void test1_player_is_there_object()
{
	Player *e=NULL;
	Id id=1;
	e = player_create(1);
	player_add_object(e, id);
	PRINT_TEST_RESULT(player_isthere_object(e, id) == FALSE);
	player_destroy(e);
}

void test2_player_is_there_object()
{
	Player *e=NULL;
	e = player_create(1);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_isthere_object(e, 3) == FALSE);
	player_destroy(e);
}

void test3_player_is_there_object()
{
	Player *e=NULL;
	e = player_create(1);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_isthere_object(e, NO_ID) == FALSE);
	player_destroy(e);
}

void test4_player_is_there_object()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_isthere_object(e, 2) == FALSE);
}

void test1_inventory_is_full()
{
	Player *e=NULL;
	e = player_create(1);
	player_set_max_inv(e, 1);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_inventory_is_full(e) == TRUE);
}

void test2_inventory_is_full()
{
	Player *e=NULL;
	e = player_create(1);
	player_set_max_inv(e, 2);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_inventory_is_full(e) == FALSE);
	player_destroy(e);
}

void test3_inventory_is_full()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_inventory_is_full(e) == FALSE);
}

void test1_inventory_is_empty()
{
	Player *e=NULL;
	e = player_create(1);
	player_set_max_inv(e, 1);
	PRINT_TEST_RESULT(player_inventory_is_empty(e) == TRUE);
}

void test2_inventory_is_empty()
{
	Player *e=NULL;
	e = player_create(1);
	player_set_max_inv(e, 1);
	player_add_object(e, 2);
	PRINT_TEST_RESULT(player_inventory_is_empty(e) == FALSE);
	player_destroy(e);
}

void test3_inventory_is_empty()
{
	Player *e=NULL;
	PRINT_TEST_RESULT(player_inventory_is_empty(e) == FALSE);
}
