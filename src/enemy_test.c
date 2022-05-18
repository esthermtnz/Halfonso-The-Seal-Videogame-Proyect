#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 28

int main(int argc, char **argv)
{
    int test = 0;
    int all =1;

    if (argc < 2)
    {
        printf("Running all test for module Enemy:\n");
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
        test1_enemy_create();
    }
    if (all || test == 2)
    {
        test1_enemy_set_name();
    }
    if (all || test == 3)
    {
        test2_enemy_set_name();
    }
    if (all || test == 4)
    {
        test3_enemy_set_name();
    }
    if (all || test == 5)
    {
        test1_enemy_get_id();
    }
    if (all || test == 6)
    {
        test2_enemy_get_id();
    }
    if (all || test == 7)
    {
        test1_enemy_get_name();
    }
    if (all || test == 8)
    {
        test2_enemy_get_name();
    }
    if (all || test == 9)
    {
        test1_enemy_set_health();
    }
    if (all || test == 10)
    {
        test2_enemy_set_health();
    }
    if (all || test == 11)
    {
        test3_enemy_set_health();
    }
    if (all || test == 12)
    {
        test1_enemy_set_location();
    }
    if (all || test == 13)
    {
        test2_enemy_set_location();
    }
    if (all || test == 14)
    {
        test3_enemy_set_location();
    }
    if (all || test == 15)
    {
        test1_enemy_get_health();
    }
    if (all || test == 16)
    {
        test2_enemy_get_health();
    }
    if (all || test == 17)
    {
        test1_enemy_get_location();
    }
    if (all || test == 18)
    {
        test2_enemy_get_location();
    }

    PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_enemy_create()
{
    int result;
    Enemy *e;
    e = enemy_create(5);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    enemy_destroy(e);
}

void test1_enemy_set_name()
{
    Enemy *e;
    e = enemy_create(5);
    PRINT_TEST_RESULT(enemy_set_name(e, "malo") == OK);
    enemy_destroy(e);
}


void test2_enemy_set_name()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_name(e, "malo") == ERROR);
}

void test3_enemy_set_name()
{
    Enemy *e;
    e = enemy_create(5);
    PRINT_TEST_RESULT(enemy_set_name(e, NULL) == ERROR);
    enemy_destroy(e);
}

void test1_enemy_get_name()
{
    Enemy *e;
    e = enemy_create(5);
    enemy_set_name(e, "adios");
    PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "adios") == 0);
    enemy_destroy(e);
}

void test2_enemy_get_name()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_name(e) == NULL);
}


void test1_enemy_get_id()
{
    Enemy *e;
    e = enemy_create(5);
    PRINT_TEST_RESULT(enemy_get_id(e) == 5);
    enemy_destroy(e);
}

void test2_enemy_get_id()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_id(e) == NO_ID);
}

void test1_enemy_set_location()
{
    Enemy *e;
    e = enemy_create(5);
    PRINT_TEST_RESULT(enemy_set_location(e, 0) == OK);
    enemy_destroy(e);
}

void test2_enemy_set_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_location(e, 0) == ERROR);
}

void test3_enemy_set_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_location(e, NO_ID) == ERROR);
}

void test1_enemy_get_location()
{
    Enemy *e;
    e = enemy_create(5);
    enemy_set_location(e, 0);
    PRINT_TEST_RESULT(enemy_get_location(e) == 0);

    enemy_destroy(e);
}

void test2_enemy_get_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_location(e) == FALSE);
}

void test1_enemy_set_health()
{
    Enemy *e;
    e = enemy_create(5);
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == OK);
    enemy_destroy(e);
}

void test2_enemy_set_health()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == ERROR);
}

void test3_enemy_set_health()
{
    Enemy *e=NULL;
    PRINT_TEST_RESULT(enemy_set_health(e, 0) == ERROR);
}

void test1_enemy_get_health()
{
    Enemy *e;
    e = enemy_create(5);
    enemy_set_health(e, 10);
    PRINT_TEST_RESULT(enemy_get_health(e) == 10);
    enemy_destroy(e);
}

void test2_enemy_get_health()
{
    Enemy *e=NULL;
    enemy_set_health(e, 10);
    PRINT_TEST_RESULT(enemy_get_health(e) == 0);
}







