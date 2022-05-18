/**
 * @file game_management_test.h
 * @author Esther Martinez
 * @brief A test for game management module
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_MANAGEMENT_TEST_H
#define GAME_MANAGEMENT_TEST_H

/**
 * @test Test game management add space
 * @post return ERROR
 */
void test1_game_management_load_spaces();

/**
 * @test Test game management add space
 * @post return OK
 */
void test2_game_management_load_spaces();

/**
 * @test Test game management add link
 * @post return ERROR
 */
void test1_game_management_load_links();

/**
 * @test Test game management add link
 * @post return OK
 */
void test2_game_management_load_links();

/**
 * @test Test game management add objects
 * @post return ERROR
 */
void test1_game_management_load_objects();

/**
 * @test Test game management add objects
 * @post return OK
 */
void test2_game_management_load_objects();

/**
 * @test Test game management add enemy
 * @post return ERROR
 */
void test1_game_management_load_enemy();

/**
 * @test Test game management add enemy
 * @post return OK
 */
void test2_game_management_load_enemy();

/**
 * @test Test game management add player
 * @post return ERROR
 */
void test1_game_management_load_player();

/**
 * @test Test game management add player
 * @post return OK
 */
void test2_game_management_load_player();

/**
 * @test Test game management save
 * @post return ERROR
 */
void test1_game_management_save();

/**
 * @test Test game management save
 * @post return OK
 */
void test2_game_management_save();

/**
 * @test Test game management load
 * @post return ERROR
 */
void test1_game_management_load();

/**
 * @test Test game management load
 * @post return OK
 */
void test2_game_management_load();
#endif