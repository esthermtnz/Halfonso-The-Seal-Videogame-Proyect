#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Test inventory creation
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();
/**
 * @test Test inventory creation
 * @post Non NULL pointer to inventory
 */
void test1_inventory_add_object();
/**
 * @test Test inventory capacity to add objects
 * @post OK
 */
void test2_inventory_add_object();
/**
 * @test Test inventory capacity to add objects
 * @post ERROR
 */
void test3_inventory_add_object();
/**
 * @test Test inventory capacity to add objects
 * @post ERROR
 */
void test1_inventory_delete_object();
/**
 * @test Test inventory capacity to destroy objects
 * @post OK
 */
void test2_inventory_delete_object();
/**
 * @test Test inventory capacity to destroy objects
 * @post ERROR
 */
void test3_inventory_delete_object();
/**
 * @test Test inventory capacity to destroy objects
 * @post ERROR
 */
void test4_inventory_delete_object();
/**
 * @test Test inventory capacity to destroy objects
 * @post ERROR
 */
void test1_inventory_isthere_obj();
/**
 * @test Test inventory check if there is object
 * @post TRUE
 */
void test2_inventory_isthere_obj();
/**
 * @test Test inventory check if there is object
 * @post FALSE
 */
void test3_inventory_isthere_obj();
/**
 * @test Test inventory check if there is object
 * @post FALSE
 */
void test4_inventory_isthere_obj();
/**
 * @test Test inventory check if there is object
 * @post FALSE
 */
void test5_inventory_isthere_obj();
/**
 * @test Test inventory check if there is object
 * @post FALSE
 */
void test1_inventory_set_max_objs();
/**
 * @test Test inventory set max objs
 * @post OK
 */
void test2_inventory_set_max_objs();
/**
 * @test Test inventory set max objs
 * @post ERROR
 */
void test3_inventory_set_max_objs();
/**
 * @test Test inventory set max objs
 * @post ERROR
 */
void test1_inventory_get_max_objs();
/**
 * @test Test inventory get max objs
 * @post 1
 */
void test2_inventory_get_max_objs();
/**
 * @test Test inventory get max objs
 * @post -1
 */
void test1_inventory_is_full();
/**
 * @test Test inventory is full
 * @post TRUE
 */
void test2_inventory_is_full();
/**
 * @test Test inventory is full
 * @post FALSE
 */
void test3_inventory_is_full();
/**
 * @test Test inventory is full
 * @post FALSE
 */
void test1_inventory_is_empty();
/**
 * @test Test inventory is empty
 * @post FALSE
 */
void test2_inventory_is_empty();
/**
 * @test Test inventory is empty
 * @post TRUE
 */
void test3_inventory_is_empty();
/**
 * @test Test inventory is empty
 * @post FALSE
 */

#endif
