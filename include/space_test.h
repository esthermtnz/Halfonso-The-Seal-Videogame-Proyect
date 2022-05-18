/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Esther Martinez
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_description setting
 * @pre String with space description
 * @post Ouput==OK 
 */
void test1_space_set_description();

/**
 * @test Test function for space_description setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_description();

/**
 * @test Test function for space_description setting
 * @pre pointer to space_description = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_description();

/**
 * @test Test function for space_id gettimg
 * @pre pointer to space = s =25
 * @post Output==25
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre pointer to space = NULL
 * @post Output==NO_ID
 */
void test2_space_get_id();

/**
 * @test Test function for space_name getting
 * @pre String with space name = "adios"
 * @post Ouput==0
 */
void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre pointer to space = NULL
 * @post Ouput==NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_description getting
 * @pre String with space description = "adios"
 * @post Ouput==0
 */
void test1_space_get_description();

/**
 * @test Test function for space_description getting
 * @pre pointer to space = NULL
 * @post Ouput==NULL
 */
void test2_space_get_description();

/**
 * @test Test function for space_add_object 
 * @pre pointer to space == 5
 * @post Ouput==ERROR
 */
void test1_space_add_object();

/**
 * @test Test function for space_add_object 
 * @pre pointer to space == 5
 * @post Ouput==OK
 */
void test2_space_add_object();

/**
 * @test Test function for space_add_object 
 * @pre pointer to space == NULL
 * @post Ouput==ERROR
 */
void test3_space_add_object();

/**
 * @test Test function for space_add_object 
 * @pre pointer to space == 5
 * @post Ouput==ERROR
 */
void test4_space_add_object();

/**
 * @test Test function for space_add_object 
 * @pre pointer to space == 5
 * @post Ouput==OK
 */
void test5_space_add_object();

/**
 * @test Test function for space_del_object 
 * @pre pointer to space == 5
 * @post Ouput==ERROR
 */
void test1_space_del_object();

/**
 * @test Test function for space_del_object 
 * @pre pointer to space == 5
 * @post Ouput==OK
 */
void test2_space_del_object();

/**
 * @test Test function for space_del_object 
 * @pre pointer to space == NULL
 * @post Ouput==ERROR
 */
void test3_space_del_object();

/**
 * @test Test function for space_del_object 
 * @pre pointer to space == ERROR
 * @post Ouput==OK
 */
void test4_space_del_object();

/**
 * @test Test function for space_del_object 
 * @pre pointer to space == ERROR
 * @post Ouput==ERROR
 */
void test5_space_del_object();

/**
 * @test Test function for space_find_object 
 * @pre pointer to space == 5
 * @post Ouput==FALSE
 */
void test1_space_find_object();

/**
 * @test Test function for space_find_object 
 * @pre pointer to space == 5
 * @post Ouput==TRUE
 */
void test2_space_find_object();

/**
 * @test Test function for space_find_object 
 * @pre pointer to space == NULL
 * @post Ouput==FALSE
 */
void test3_space_find_object();

/**
 * @test Test function for space_find_object 
 * @pre pointer to space == 5
 * @post Ouput==FALSE
 */
void test4_space_find_object();

/**
 * @test Test function for space_find_object 
 * @pre pointer to space == 5
 * @post Ouput==FALSE
 */
void test5_space_find_object();

/**
 * @test Test function for space_gdesc getting
 * @pre pointer to space == 5
 * @pre position == 5
 * @post Ouput!=NULL
 */
void test1_space_get_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre pointer to space == 5
 * @pre position == -1
 * @post Ouput==NULL
 */
void test2_space_get_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre pointer to space == 5
 * @pre position == 5
 * @post Ouput==OK
 */
void test1_space_set_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre pointer to space == 5
 * @pre position == 5
 * @post Ouput==ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Test function for space_illumination getting
 * @pre pointer to space == 5
 * @post Ouput==TRUE
 */
void test1_space_get_illumination();

/**
 * @test Test function for space_illumination getting
 * @pre pointer to space == NULL
 * @post Ouput==FALSE
 */
void test2_space_get_illumination();

/**
 * @test Test function for space_illumination getting
 * @pre pointer to space == 5
 * @post Ouput!=TRUE
 */
void test3_space_get_illumination();

/**
 * @test Test function for space_illumination setting
 * @pre pointer to space == 5
 * @pre illumination
 * @post Ouput==OK
 */
void test1_space_set_illumination();

/**
 * @test Test function for space_illumination setting
 * @pre pointer to space == NULL
 * @pre illumination
 * @post Ouput==ERROR
 */
void test2_space_set_illumination();

/**
 * @test Test function for space_illudescription getting
 * @pre String with space description = "adios"
 * @post Ouput==0
 */
void test1_space_get_illudescription();

/**
 * @test Test function for space_illudescription getting
 * @pre pointer to space = NULL
 * @post Ouput==NULL
 */
void test2_space_get_illudescription();

/**
 * @test Test function for space_illudescription setting
 * @pre String with space description
 * @post Ouput==OK 
 */
void test1_space_set_illudescription();

/**
 * @test Test function for space_illudescription setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_illudescription();

/**
 * @test Test function for space_illudescription setting
 * @pre pointer to space_description = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_illudescription();

#endif
