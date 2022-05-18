#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "set.h"
#include "set_test.h"
#include "test.h"

/**
 * @brief Max amount of test
 */
#define MAX_TESTS 28

/**
 * @brief Main function for SET unit tests.
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
  int all = 1;

  if (argc < 2)
  {
    printf("Running all test for module Space:\n");
  }
  else
  {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS)
    {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)
    test1_set_create();

  if (all || test == 2)
    test1_set_add_object();
  if (all || test == 3)
    test2_set_add_object();
  if (all || test == 4)
    test3_set_add_object();
  if (all || test == 5)
    test4_set_add_object();
  if (all || test == 6)
    test5_set_add_object();

  if (all || test == 7)
    test1_set_del_object();
  if (all || test == 8)
    test2_set_del_object();
  if (all || test == 9)
    test3_set_del_object();
  if (all || test == 10)
    test4_set_del_object();
  if (all || test == 11)
    test5_set_del_object();

  if (all || test == 12)
    test1_set_find_object();
  if (all || test == 13)
    test2_set_find_object();
  if (all || test == 14)
    test3_set_find_object();
  if (all || test == 15)
    test4_set_find_object();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create()
{
  int result;
  Set *s;
  s = set_create();
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test1_set_add_object()
{
  int result;
  Set *s;
  s = set_create();
  result = set_add_object(s, NO_ID) == ERROR;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_add_object()
{
  int result;
  Set *s;
  s = set_create();
  result = set_add_object(s, 1) == OK;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test3_set_add_object()
{
  int result;
  Set *s = NULL;
  result = set_add_object(s, 1) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test4_set_add_object()
{
  int result, i;
  Set *s = NULL;
  s = set_create();

  for (i = 0; i < MAX_ID; i++)
  {
    set_add_object(s, i);
  }
  result = set_add_object(s, 6) == ERROR;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test5_set_add_object()
{
  int result, i;
  Set *s = NULL;
  s = set_create();

  for (i = 1; i < MAX_ID; i++)
  {
    set_add_object(s, i);
  }
  result = set_add_object(s, 4) == OK;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test1_set_del_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_del_object(s, NO_ID) == ERROR;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_del_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_del_object(s, 1) == OK;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test3_set_del_object()
{
  int result;
  Set *s = NULL;
  set_add_object(s, 1);
  result = set_del_object(s, 1) == ERROR;
  PRINT_TEST_RESULT(result);
}

void test4_set_del_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  set_del_object(s, 1);
  result = set_del_object(s, 2) == ERROR;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test5_set_del_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_del_object(s, 2) == ERROR;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test1_set_find_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_find_object(s, NO_ID) == FALSE;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_find_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_find_object(s, 1) == TRUE;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test3_set_find_object()
{
  int result;
  Set *s = NULL;
  set_add_object(s, 1);
  result = set_find_object(s, 1) == FALSE;
  PRINT_TEST_RESULT(result);
}

void test4_set_find_object()
{
  int result;
  Set *s;
  s = set_create();
  set_add_object(s, 1);
  result = set_find_object(s, 2) == FALSE;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}
