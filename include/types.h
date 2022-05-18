/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

/**
 * @brief maximum word size of the word
 */
#define WORD_SIZE 1000

/**
 * @brief macro which asigns a variable the value -1
 */
#define NO_ID -1

/**
 * @brief macro which asigns a variable the value -1
 */
#define NO_RULES -1

/**
 * @brief macro that shows the maximum spaces
 */
#define MAX_SPACES 100

/**
 * @brief macro that shows the maximum links
 */
#define MAX_LINKS 4*MAX_SPACES

/**
 * @brief macro that shows the maximum objects
 */
#define MAX_OBJ 20

/**
 * @brief macro that sets the first space to the value 1
 */
#define FIRST_SPACE 1

/**
 * @brief macro that sets the first link to the value 1
 */
#define FIRST_LINK 1


/*REMEMBER TO INCREASE THEM ON I3 */

/**
 * @brief maximum size of the array of ids
 */
#define MAX_ID 5 

/**
 * @brief maximum size of the random numbers
 */
#define MAX_RAND 10

/**
 * @brief variable of type long
 */
typedef long Id;

/**
 * @brief BOOL
 * 
 * The returns of a boolean function
 */
typedef enum
{
  FALSE,
  TRUE
} BOOL;

/**
 * @brief STATUS
 * 
 * The returns of a function type Status
 */
typedef enum
{
  ERROR,
  OK
} STATUS;

/**
 * @brief DIRECTION
 * 
 * The returns of a all the possible directions
 */
typedef enum
{
  N,
  S,
  E,
  W,
  U,
  D
} DIRECTION;

/**
 * @brief LINKST
 * 
 * The returns open or close
 */
typedef enum
{
  OPEN,
  CLOSE
} LINKST;

#endif
