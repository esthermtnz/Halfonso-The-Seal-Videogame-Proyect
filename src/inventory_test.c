/**
 * @brief It tests Inventory module
 *
 * @file inventory_test.c
 * @author Jaime Sánchez Esteban
 * @version 1.0
 * @date 22-03-2022
 * @copyright GNU Public License
 */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory.h"
#include "set.h"
#include "inventory_test.h"
#include "test.h"

/**
 * @brief Maximum number of test
 */
#define MAX_TESTS 24

/**
 * @brief Main function for inventory unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char** argv) 
{
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  
  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test1_inventory_add_object();
  if (all || test == 3) test2_inventory_add_object();
  if (all || test == 4) test3_inventory_add_object();
  if (all || test == 5) test1_inventory_delete_object();
  if (all || test == 6) test2_inventory_delete_object();
  if (all || test == 7) test3_inventory_delete_object();
  if (all || test == 8) test4_inventory_delete_object();
  if (all || test == 9) test1_inventory_isthere_obj();
  if (all || test == 10) test2_inventory_isthere_obj();
  if (all || test == 11) test3_inventory_isthere_obj();
  if (all || test == 12) test4_inventory_isthere_obj();
  if (all || test == 13) test5_inventory_isthere_obj();
  if (all || test == 14) test1_inventory_set_max_objs();
  if (all || test == 15) test2_inventory_set_max_objs();
  if (all || test == 16) test3_inventory_set_max_objs();
  if (all || test == 17) test1_inventory_get_max_objs();
  if (all || test == 18) test2_inventory_get_max_objs();
  if (all || test == 19) test1_inventory_is_full();
  if (all || test == 20) test2_inventory_is_full();
  if (all || test == 21) test3_inventory_is_full();
  if (all || test == 22) test1_inventory_is_empty();
  if (all || test == 23) test2_inventory_is_empty();
  if (all || test == 24) test3_inventory_is_empty();
  
  PRINT_PASSED_PERCENTAGE;
  return 1;
}

void test1_inventory_create() {
	Inventory *inv = NULL;
	inv = inventory_create();
	PRINT_TEST_RESULT(inv != NULL);
	inventory_destroy(inv);
}

void test1_inventory_add_object() {
	Inventory *inv = NULL;
	Id id = 1;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	PRINT_TEST_RESULT(inventory_add_object(inv, id) == OK);
	inventory_destroy(inv);
}

void test2_inventory_add_object() {
	Inventory *inv = NULL;
	Id id = 1;
	PRINT_TEST_RESULT(inventory_add_object(inv, id) == ERROR);
	inventory_destroy(inv);
}

void test3_inventory_add_object() {
	Inventory *inv = NULL;
	Id id = NO_ID;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_add_object(inv, id) == ERROR);
	inventory_destroy(inv);
}

void test1_inventory_delete_object() {
	Inventory *inv = NULL;
	Id id = 1;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, id);
	PRINT_TEST_RESULT(inventory_delete_object(inv, id) == OK);
	inventory_destroy(inv);
}

void test2_inventory_delete_object() {
	Inventory *inv = NULL;
	Id id = 1;
	PRINT_TEST_RESULT(inventory_delete_object(inv, id) == ERROR);
	inventory_destroy(inv);
}

void test3_inventory_delete_object() {
	Inventory *inv = NULL;
	Id id = NO_ID;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, id);
	PRINT_TEST_RESULT(inventory_delete_object(inv, id) == ERROR);
	inventory_destroy(inv);
}

void test4_inventory_delete_object() {
	Inventory *inv = NULL;
	Id id = 1;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_delete_object(inv, id) == ERROR);
	inventory_destroy(inv);
}

void test1_inventory_isthere_obj() {
	Inventory *inv = NULL;
	Id id = 1;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, id);
	PRINT_TEST_RESULT(inventory_isthere_obj(inv, id) == TRUE);
	inventory_destroy(inv);
}

void test2_inventory_isthere_obj() {
	Inventory *inv = NULL;
	Id id = 1, id2 = 2;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, id);
	PRINT_TEST_RESULT(inventory_isthere_obj(inv, id2) == FALSE);
	inventory_destroy(inv);
}

void test3_inventory_isthere_obj() {
	Inventory *inv = NULL;
	Id id = 1;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_isthere_obj(inv, id) == FALSE);
	inventory_destroy(inv);
}

void test4_inventory_isthere_obj() {
	Inventory *inv = NULL;
	Id id = 1;
	PRINT_TEST_RESULT(inventory_isthere_obj(inv, id) == FALSE);
	inventory_destroy(inv);
}

void test5_inventory_isthere_obj() {
	Inventory *inv = NULL;
	Id id = NO_ID;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_isthere_obj(inv, id) == FALSE);
	inventory_destroy(inv);
}

void test1_inventory_set_max_objs() {
	Inventory *inv = NULL;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_set_max_objs(inv, 5) == OK);
	inventory_destroy(inv);
}

void test2_inventory_set_max_objs() {
	Inventory *inv = NULL;
	PRINT_TEST_RESULT(inventory_set_max_objs(inv, 5) == ERROR);
	inventory_destroy(inv);
}

void test3_inventory_set_max_objs() {
	Inventory *inv = NULL;
	inv = inventory_create();
	PRINT_TEST_RESULT(inventory_set_max_objs(inv, -1) == ERROR);
	inventory_destroy(inv);
}

void test1_inventory_get_max_objs() {
	Inventory *inv = NULL;
	inv = inventory_create();
	inventory_set_max_objs(inv, 5);
	PRINT_TEST_RESULT(inventory_get_max_objs(inv) == 5);
	inventory_destroy(inv);
}

void test2_inventory_get_max_objs() {
	Inventory *inv = NULL;
	PRINT_TEST_RESULT(inventory_get_max_objs(inv) == -1);
	inventory_destroy(inv);
}

void test1_inventory_is_full() {
	Inventory *inv = NULL;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, 1);
	PRINT_TEST_RESULT(inventory_is_full(inv) == TRUE);
	inventory_destroy(inv);
}

void test2_inventory_is_full() {
	Inventory *inv = NULL;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	PRINT_TEST_RESULT(inventory_is_full(inv) == FALSE);
	inventory_destroy(inv);
}

void test3_inventory_is_full() {
	Inventory *inv = NULL;
	PRINT_TEST_RESULT(inventory_is_full(inv) == FALSE);
	inventory_destroy(inv);
}

void test1_inventory_is_empty() {
	Inventory *inv = NULL;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	inventory_add_object(inv, 1);
	PRINT_TEST_RESULT(inventory_is_empty(inv) == FALSE);
	inventory_destroy(inv);
}

void test2_inventory_is_empty() {
	Inventory *inv = NULL;
	inv = inventory_create();
	inventory_set_max_objs(inv, 1);
	PRINT_TEST_RESULT(inventory_is_empty(inv) == TRUE);
	inventory_destroy(inv);
}

void test3_inventory_is_empty() {
	Inventory *inv = NULL;
	PRINT_TEST_RESULT(inventory_is_empty(inv) == FALSE);
	inventory_destroy(inv);
}
