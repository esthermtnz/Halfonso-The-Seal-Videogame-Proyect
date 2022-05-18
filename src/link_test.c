/**
 * @brief It tests link module
 *
 * @file link_test.c
 * @author Esther Martinez
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "link_test.h"
#include "test.h"
/**
 * @brief Max number of text
 */
#define MAX_TESTS 32

/**
 * @brief Main function for link unit tests.
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
    printf("Running all test for module link:\n");
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
    test1_link_create();
  if (all || test == 2)
    test2_link_create();
  if (all || test == 3)
    test1_link_get_name();
  if (all || test == 4)
    test2_link_get_name();
  if (all || test == 5)
    test1_link_set_name();
  if (all || test == 6)
    test2_link_set_name();
  if (all || test == 7)
    test3_link_set_name();
  if (all || test == 8)
    test1_link_get_id();
  if (all || test == 9)
    test2_link_get_id();
  if (all || test == 10)
    test1_link_get_origin();
  if (all || test == 11)
    test2_link_get_origin();
  if (all || test == 12)
    test3_link_get_origin();
  if (all || test == 13)
    test1_link_set_origin();
  if (all || test == 14)
    test2_link_set_origin();
  if (all || test == 15)
    test3_link_set_origin();
  if (all || test == 16)
    test1_link_get_destination();
  if (all || test == 17)
    test2_link_get_destination();
  if (all || test == 18)
    test3_link_get_destination();
  if (all || test == 19)
    test1_link_set_destination();
  if (all || test == 20)
    test2_link_set_destination();
  if (all || test == 21)
    test3_link_set_destination();
  if (all || test == 22)
    test1_link_get_direction();
  if (all || test == 23)
    test2_link_get_direction();
  if (all || test == 24)
    test3_link_get_direction();
  if (all || test == 25)
    test1_link_set_direction();
  if (all || test == 26)
    test2_link_set_direction();
  if (all || test == 27)
    test1_link_get_status();
  if (all || test == 28)
    test2_link_get_status();
  if (all || test == 29)
    test3_link_get_status();
  if (all || test == 30)
    test1_link_set_status();
  if (all || test == 31)
    test2_link_set_status();
  if (all || test == 32)
    test3_link_set_status();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create()
{
  int result;
  Link *l;
  l = link_create(5);
  result = l != NULL;
  PRINT_TEST_RESULT(result);
  link_destroy(l);
}

void test2_link_create()
{
  Link *l;
  l = link_create(4);
  PRINT_TEST_RESULT(link_get_id(l) == 4);
  link_destroy(l);
}

void test1_link_get_name()
{
  Link *l;
  l = link_create(1);
  link_set_name(l, "adios");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "adios") == 0);
  link_destroy(l);
}

void test2_link_get_name()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_set_name()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, "hola") == OK);
  link_destroy(l);
}

void test2_link_set_name()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_name(l, "hola") == ERROR);
}

void test3_link_set_name()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
  link_destroy(l);
}

void test1_link_get_id()
{
  Link *l;
  l = link_create(25);
  PRINT_TEST_RESULT(link_get_id(l) == 25);
  link_destroy(l);
}

void test2_link_get_id()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_get_origin()
{
  Link *l;
  l = link_create(5);
  link_set_origin(l, 1);
  PRINT_TEST_RESULT(link_get_origin(l) == 1);
  link_destroy(l);
}

void test2_link_get_origin()
{
  Link *l = NULL;
  link_set_origin(l, 1);
  PRINT_TEST_RESULT(link_get_origin(l) == NO_ID);
}

void test3_link_get_origin()
{
  Link *l = NULL;
  link_set_origin(l, NO_ID);
  PRINT_TEST_RESULT(link_get_origin(l) == NO_ID);
}

void test1_link_set_origin()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_origin(l, 1) == OK);
  link_destroy(l);
}

void test2_link_set_origin()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_origin(l, 1) == ERROR);
}

void test3_link_set_origin()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_origin(l, NO_ID) == ERROR);
}

void test1_link_get_destination()
{
  Link *l;
  l = link_create(5);
  link_set_destination(l, 1);
  PRINT_TEST_RESULT(link_get_destination(l) == 1);
  link_destroy(l);
}

void test2_link_get_destination()
{
  Link *l = NULL;
  link_set_destination(l, 1);
  PRINT_TEST_RESULT(link_get_destination(l) == NO_ID);
}

void test3_link_get_destination()
{
  Link *l = NULL;
  link_set_destination(l, NO_ID);
  PRINT_TEST_RESULT(link_get_destination(l) == NO_ID);
}

void test1_link_set_destination()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_destination(l, 1) == OK);
  link_destroy(l);
}

void test2_link_set_destination()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_destination(l, 1) == ERROR);
}

void test3_link_set_destination()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_destination(l, NO_ID) == ERROR);
}

void test1_link_get_direction()
{
  Link *l;
  l = link_create(5);
  link_set_direction(l, S);
  PRINT_TEST_RESULT(link_get_direction(l) == S);
  link_destroy(l);
}

void test2_link_get_direction()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_direction(l) == N);
}

void test3_link_get_direction()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_direction(l) == N);
  link_destroy(l);
}

void test1_link_set_direction()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_direction(l, S) == OK);
  link_destroy(l);
}

void test2_link_set_direction()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_direction(l, E) == ERROR);
}


void test1_link_get_status()
{
  Link *l;
  l = link_create(5);
  link_set_status(l, OPEN);
  PRINT_TEST_RESULT(link_get_status(l) == OPEN);
  link_destroy(l);
}

void test2_link_get_status()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_status(l) == CLOSE);
}

void test3_link_get_status()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_status(l) == CLOSE);
  link_destroy(l);
}

void test1_link_set_status()
{
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_status(l, OPEN) == OK);
  link_destroy(l);
}

void test2_link_set_status()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_status(l, OPEN) == ERROR);
}

void test3_link_set_status()
{
  Link *l = NULL;
  l = link_create(NO_ID);
  PRINT_TEST_RESULT(link_set_status(l, OPEN) == ERROR);
  link_destroy(l);
}
