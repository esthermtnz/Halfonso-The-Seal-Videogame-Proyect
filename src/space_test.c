/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Profesores Pprog
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "space.h"
#include "space_test.h"
#include "test.h"
#include "set.h"
/**
 * @brief Max amount of test
 */
#define MAX_TESTS 43

/** 
 * @brief Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_set_name();
  if (all || test == 4) test2_space_set_name();
  if (all || test == 5) test3_space_set_name();
  if (all || test == 6) test1_space_get_name();
  if (all || test == 7) test2_space_get_name();
  if (all || test == 8) test1_space_set_description();
  if (all || test == 9) test2_space_set_description();
  if (all || test == 10) test3_space_set_description();
  if (all || test == 11) test1_space_get_description();
  if (all || test == 12) test2_space_get_description();
  if (all || test == 13) test1_space_get_id();
  if (all || test == 14) test2_space_get_id();
  if (all || test == 15) test1_space_add_object();
  if (all || test == 16) test2_space_add_object();
  if (all || test == 17) test3_space_add_object();
  if (all || test == 18) test4_space_add_object();
  if (all || test == 19) test5_space_add_object();
  if (all || test == 20) test1_space_del_object();
  if (all || test == 21) test2_space_del_object();
  if (all || test == 22) test3_space_del_object();
  if (all || test == 23) test4_space_del_object();
  if (all || test == 24) test5_space_del_object();
  if (all || test == 25) test1_space_find_object();
  if (all || test == 26) test2_space_find_object();
  if (all || test == 27) test3_space_find_object();
  if (all || test == 28) test4_space_find_object();
  if (all || test == 29) test5_space_find_object();
  if (all || test == 30) test1_space_get_gdesc();
  if (all || test == 31) test2_space_get_gdesc();
  if (all || test == 32) test1_space_set_gdesc();
  if (all || test == 33) test2_space_set_gdesc();
  if (all || test == 34) test1_space_get_illumination();
  if (all || test == 35) test2_space_get_illumination();
  if (all || test == 36) test3_space_get_illumination();
  if (all || test == 37) test1_space_set_illumination();
  if (all || test == 38) test2_space_set_illumination();
  if (all || test == 39) test1_space_set_illudescription();
  if (all || test == 40) test2_space_set_illudescription();
  if (all || test == 41) test3_space_set_illudescription();
  if (all || test == 42) test1_space_get_illudescription();
  if (all || test == 43) test2_space_get_illudescription();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_set_description() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_description(s, "hola") == ERROR);
}

void test3_space_set_description() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_description() {
  Space *s;
  s = space_create(1);
  space_set_description(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_description(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description(s) == NULL);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}


void test1_space_add_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_add_object(s,NO_ID) == ERROR);
  space_destroy(s);
}

void test2_space_add_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_add_object(s,1) == OK);
  space_destroy(s);
}

void test3_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s,1) == ERROR);
}

void test4_space_add_object() {
  int i;
  Space *s = NULL;
  s = space_create(5);
  for(i=0;i<MAX_ID;i++){
    space_add_object(s,i);
  }
  PRINT_TEST_RESULT(space_add_object(s,1) == ERROR);
  space_destroy(s);
}

void test5_space_add_object() {
  int i;
  Space *s = NULL;
  s = space_create(5);
  for(i=1;i<MAX_ID;i++){
    space_add_object(s,i);
  }
  PRINT_TEST_RESULT(space_add_object(s,1) == OK);
  space_destroy(s);
}


void test1_space_del_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_del_object(s,NO_ID) == ERROR);
  space_destroy(s);
}

void test2_space_del_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  PRINT_TEST_RESULT(space_del_object(s,1) == OK);
  space_destroy(s);
}

void test3_space_del_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_del_object(s,1) == ERROR);
}

void test4_space_del_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  PRINT_TEST_RESULT(space_del_object(s,2) == ERROR);
  space_destroy(s);
}

void test5_space_del_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  space_del_object(s,1);
  PRINT_TEST_RESULT(space_del_object(s,2) == ERROR);
  space_destroy(s);
}


void test1_space_find_object() {
  Space *s = NULL;
  s = space_create(5);
  PRINT_TEST_RESULT(space_find_object(s,NO_ID) == FALSE);
  space_destroy(s);
}

void test2_space_find_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  PRINT_TEST_RESULT(space_find_object(s,1) == TRUE);
  space_destroy(s);
}

void test3_space_find_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_find_object(s,1) == FALSE);
}

void test4_space_find_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  PRINT_TEST_RESULT(space_find_object(s,2) == FALSE);
  space_destroy(s);
}

void test5_space_find_object() {
  Space *s = NULL;
  s = space_create(5);
  space_add_object(s,1);
  space_del_object(s,1);
  PRINT_TEST_RESULT(space_find_object(s,1) == FALSE);
  space_destroy(s);
}

void test1_space_get_gdesc() {
  Space *s;
  int pos = 5;
  s = space_create(5);
  PRINT_TEST_RESULT(space_get_gdesc(s,pos) != NULL);
  space_destroy(s);
}

void test2_space_get_gdesc() {
  Space *s = NULL;
  int pos = -1;
  PRINT_TEST_RESULT(space_get_gdesc(s,pos) == NULL);
}

void test1_space_set_gdesc() {
  Space *s;
  int pos = 5;
  char *string = "         ";
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_gdesc(s,string,pos) == OK);
}

void test2_space_set_gdesc() {
  Space *s = NULL;
  int pos = -1;
  char *string =  "";
  PRINT_TEST_RESULT(space_set_gdesc(s,string,pos) == ERROR);
}

void test1_space_get_illumination(){
  Space *s;
  s = space_create(5);
  space_set_illumination(s,TRUE);
  PRINT_TEST_RESULT(space_get_illumination(s) == TRUE);
  space_destroy(s);
}

void test2_space_get_illumination(){
  Space *s = NULL;
  space_set_illumination(s,TRUE);
  PRINT_TEST_RESULT(space_get_illumination(s) == FALSE);
}

void test3_space_get_illumination(){
  Space *s;
  s = space_create(5);
  space_set_illumination(s,FALSE);
  PRINT_TEST_RESULT(space_get_illumination(s) != TRUE);
  space_destroy(s);
}

void test1_space_set_illumination(){
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_illumination(s,TRUE) == OK);
  space_destroy(s);
}

void test2_space_set_illumination(){
  Space *s  = NULL;
  PRINT_TEST_RESULT(space_set_illumination(s,TRUE) == ERROR);
}

void test1_space_set_illudescription() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_illudescription(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_illudescription() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_illudescription(s, "hola") == ERROR);
}

void test3_space_set_illudescription() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_illudescription(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_illudescription() {
  Space *s;
  s = space_create(1);
  space_set_illudescription(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_illudescription(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_illudescription() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_illudescription(s) == NULL);
}

