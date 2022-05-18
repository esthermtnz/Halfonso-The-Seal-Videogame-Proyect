/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author Esther Martinez
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef link_TEST_H
#define link_TEST_H

/**
 * @test Test link creation
 * @pre link ID 
 * @post Non NULL pointer to link 
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre link ID 
 * @post Non NULL pointer to link 
 */
void test2_link_create();

/**
 * @test Test function for link_id gettimg
 * @pre pointer to link = s =25
 * @post Output==25
 */
void test1_link_get_id();

/**
 * @test Test function for link_id getting
 * @pre pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_id();


/**
 * @test Test function for link_name getting
 * @pre String with link name = "adios"
 * @post Ouput==0
 */
void test1_link_get_name();

/**
 * @test Test function for link_name getting
 * @pre pointer to link = NULL
 * @post Ouput==NULL
 */
void test2_link_get_name();

/**
 * @test Test function for link_name setting
 * @pre String with link name
 * @post Ouput==OK 
 */
void test1_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre pointer to link = NULL 
 * @post Output==ERROR
 */
void test2_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre pointer to link_name = NULL (point to link = NON NULL) 
 * @post Output==ERROR
 */
void test3_link_set_name();

/**
 * @test Test function for link_origin getting
 * @pre pointer to link
 * @post Output==1
 */
void test1_link_get_origin();

/**
 * @test Test function for link_origin getting
 * @pre pointer to link = NULL
 * @post Output==NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test function for link_origin getting
 * @pre pointer to link = NULL
 * @post Output==NO_ID
 */
void test3_link_get_origin();

/**
 * @test Test function for link_origin setting
 * @pre pointer to link 
 * @post Output==OK
 */
void test1_link_set_origin();

/**
 * @test Test function for link_origin setting
 * @pre pointer to link =NULL 
 * @post Output==ERROR
 */
void test2_link_set_origin();

/**
 * @test Test function for link_origin setting
 * @pre pointer to link  =NULL 
 * @post Output==ERROR
 */
void test3_link_set_origin();

/**
 * @test Test function for link_destination getting
 * @pre pointer to link
 * @post Output==1
 */
void test1_link_get_destination();

/**
 * @test Test function for link_destination getting
 * @pre pointer to link = NULL
 * @post Output== NO_ID
 */
void test2_link_get_destination();

/**
 * @test Test function for link_destination getting
 * @pre pointer to link = NULL
 * @post Output== NO_ID
 */
void test3_link_get_destination();

/**
 * @test Test function for link_destination setting
 * @pre pointer to link
 * @post Output== OK
 */
void test1_link_set_destination();

/**
 * @test Test function for link_destination setting
 * @pre pointer to link = NULL
 * @post Output== ERROR
 */
void test2_link_set_destination();

/**
 * @test Test function for link_destination setting
 * @pre pointer to link = NULL
 * @post Output== ERROR
 */
void test3_link_set_destination();

/**
 * @test Test function for link_direction getting
 * @pre pointer to link
 * @post Output== S
 */
void test1_link_get_direction();

/**
 * @test Test function for link_direction getting
 * @pre pointer to link = NULL
 * @post Output== N
 */
void test2_link_get_direction();

/**
 * @test Test function for link_direction getting
 * @pre pointer to link = NULL
 * @post Output== N
 */
void test3_link_get_direction();

/**
 * @test Test function for link_direction setting
 * @pre pointer to link
 * @post Output== OK
 */
void test1_link_set_direction();

/**
 * @test Test function for link_direction setting
 * @pre pointer to link = NULL
 * @post Output== ERROR
 */
void test2_link_set_direction();

/**
 * @test Test function for link_status getting
 * @pre pointer to link
 * @post Output== OPEN
 */
void test1_link_get_status();

/**
 * @test Test function for link_status getting
 * @pre pointer to link = NULL
 * @post Output== CLOSE
 */
void test2_link_get_status();

/**
 * @test Test function for link_status getting
 * @pre pointer to link = NULL
 * @post Output== CLOSE
 */
void test3_link_get_status();

/**
 * @test Test function for link_status setting
 * @pre pointer to link
 * @post Output== OK
 */
void test1_link_set_status();

/**
 * @test Test function for link_status setting
 * @pre pointer to link = NULL
 * @post Output== ERROR
 */
void test2_link_set_status();

/**
 * @test Test function for link_status setting
 * @pre pointer to link = NULL
 * @post Output== ERROR
 */
void test3_link_set_status();

#endif
