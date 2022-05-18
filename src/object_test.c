/**
 * @brief It tests player module
 *
 * @file object_test.c
 * @author Jaime Sanchez Esteban
 * @version 1.0
 * @date 05-04-2022
 * @copyright GNU Public License
 */
 #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "object_test.h"
#include "object.h"
#include "test.h"
/**
 * @brief Max number of tests
 */
#define MAX_TESTS 14

/**
 * @brief Main function for object unit tests.
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
        printf("Running all test for module object:\n");
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
        test1_object_create();
    }
    if (all || test == 2)
    {
        test2_object_create();
    }
    if (all || test == 3)
    {
        test1_object_get_id();
    }
    if (all || test == 4)
    {
        test2_object_get_id();
    }
    if (all || test == 5)
    {
        test1_object_set_name();
    }
    if (all || test == 6)
    {
        test2_object_set_name();
    }
    if (all || test == 7)
    {
        test3_object_set_name();
    }
    if (all || test == 8)
    {
        test1_object_get_name();
    }
    if (all || test == 9)
    {
        test2_object_get_name();
    }
    if (all || test == 10)
    {
        test1_object_set_description();
    }
    if (all || test == 11)
    {
        test2_object_set_description();
    }
    if (all || test == 12)
    {
        test3_object_set_description();
    }
    if (all || test == 13)
    {
        test1_object_get_description();
    }
    if (all || test == 14)
    {
        test2_object_get_description();
    }
    
    
    PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_object_create()
{
	Object *o=NULL;
	o = object_create(1);
	PRINT_TEST_RESULT(o != NULL);
	object_destroy(o);
}

void test2_object_create()
{
	Object *o=NULL;
	o = object_create(NO_ID);
	PRINT_TEST_RESULT(o == NULL);
}

void test1_object_get_id()
{
	Object *o=NULL;
	o = object_create(1);
	PRINT_TEST_RESULT(object_get_id(o) == 1);
	object_destroy(o);
}

void test2_object_get_id()
{
	Object *o=NULL;
	PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_set_name()
{
	Object *o=NULL;
	char name[10] = "prueba";
	o = object_create(1);
	PRINT_TEST_RESULT(object_set_name(o, name) == OK);
	object_destroy(o);
}

void test2_object_set_name()
{
	Object *o=NULL;
	char name[10] = "prueba";
	PRINT_TEST_RESULT(object_set_name(o, name) == ERROR);
}

void test3_object_set_name()
{
	Object *o=NULL;
	char *name = NULL;
	o = object_create(1);
	PRINT_TEST_RESULT(object_set_name(o, name) == ERROR);
	object_destroy(o);
}

void test1_object_get_name()
{
	Object *o=NULL;
	char name[10] = "prueba";
	o = object_create(1);
	object_set_name(o, name);
	PRINT_TEST_RESULT(strcmp("prueba", object_get_name(o)) == 0);
	object_destroy(o);
}

void test2_object_get_name()
{
	Object *o=NULL;
	PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_set_description()
{
	Object *o=NULL;
	char description[10] = "prueba";
	o = object_create(1);
	PRINT_TEST_RESULT(object_set_description(o, description) == OK);
	object_destroy(o);
}

void test2_object_set_description()
{
	Object *o=NULL;
	char description[10] = "prueba";
	PRINT_TEST_RESULT(object_set_name(o, description) == ERROR);
}

void test3_object_set_description()
{
	Object *o=NULL;
	char *description = NULL;
	o = object_create(1);
	PRINT_TEST_RESULT(object_set_description(o, description) == ERROR);
	object_destroy(o);
}

void test1_object_get_description()
{
	Object *o=NULL;
	char description[10] = "prueba";
	o = object_create(1);
	object_set_description(o, description);
	PRINT_TEST_RESULT(strcmp("prueba", object_get_description(o)) == 0);
	object_destroy(o);
}

void test2_object_get_description()
{
	Object *o=NULL;
	PRINT_TEST_RESULT(object_get_description(o) == NULL);
}
