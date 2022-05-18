#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_management.h"
#include "game_management_test.h"
#include "test.h"
#include "game.h"
#include "space.h"
#include "object.h"
#include "inventory.h"
#include "link.h"

/**
 * @brief Max amount of test
 */
#define MAX_TESTS 28

/**
 * @brief Main function for GAME MANAGEMENT unit tests.
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
        test1_game_management_load_spaces();
    if (all || test == 2)
        test2_game_management_load_spaces();
    if (all || test == 3)
        test1_game_management_load_links();
    if (all || test == 4)
        test2_game_management_load_links();
    if (all || test == 5)
        test2_game_management_load_enemy();
    if (all || test == 6)
        test2_game_management_load_enemy();
    if (all || test == 7)
        test2_game_management_load_player();
    if (all || test == 8)
        test2_game_management_load_player();
    if (all || test == 9)
        test2_game_management_load_objects();
    if (all || test == 10)
        test2_game_management_load_objects();
    if (all || test == 11)
        test2_game_management_save();
    if (all || test == 12)
        test2_game_management_save();
    if (all || test == 13)
        test2_game_management_load();
    if (all || test == 14)
        test2_game_management_load();

    PRINT_PASSED_PERCENTAGE;
    return 1;
}

void test1_game_management_load_spaces()
{
    int result;
    Game *g = NULL;

    result = game_management_load_spaces(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load_spaces()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "hormiguero.dat");
    
    g = game_create();
    result = game_management_load_spaces(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_load_links()
{
    int result;
    Game *g = NULL;

    result = game_management_load_links(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load_links()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "hormiguero.dat");

    g = game_create();
    result = game_management_load_links(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_load_enemy()
{
    int result;
    Game *g = NULL;

    result = game_management_load_links(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load_enemy()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "hormiguero.dat");

    g = game_create();
    result = game_management_load_links(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_load_player()
{
    int result;
    Game *g = NULL;

    result = game_management_load_player(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load_player()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "hormiguero.dat");

    g = game_create();
    result = game_management_load_player(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_load_objects()
{
    int result;
    Game *g = NULL;

    result = game_management_load_objects(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load_objects()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "hormiguero.dat");

    g = game_create();
    result = game_management_load_objects(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_save()
{
    int result;
    Game *g = NULL;

    result = game_management_save(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_save()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "test_managementsave.dat");

    g = game_create();
    result = game_management_save(g, f) == OK;
    PRINT_TEST_RESULT(result);
}

void test1_game_management_load()
{
    int result;
    Game *g = NULL;

    result = game_management_load(g, NULL) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test2_game_management_load()
{
    int result;
    Game *g;
    char f[255];

    strcpy(f, "test_managementsave.dat");

    g = game_create();
    result = game_management_load(g, f) == OK;
    PRINT_TEST_RESULT(result);
}