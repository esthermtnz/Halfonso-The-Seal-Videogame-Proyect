/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H
/**
 * @brief Number of commands
 */
#define N_CMDT 2
/**
 * @brief Number of commands
 */
#define N_CMD 13

/**
 * @brief type of comand
 */
typedef enum enum_CmdType
{
  CMDS,
  CMDL
} T_CmdType;

/**
 * @brief Enumeration of all posible commands
 */
typedef enum enum_Command
{
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  TAKE,
  DROP,
  MOVE,
  ATTACK,
  TURNON,
  TURNOFF,
  OPENLINK,
  INSPECT,
  SAVE,
  LOAD
} T_Command;

/**
 * @brief Its scans the command bar and depending on the command introduces it keeps reading or not
 * @author Pablo Vargas
 *
 * player_create allocates memory for a new player
 *  and initializes its members
 * @param id the identification number for the new player
 * @return a new player, initialized
 */
T_Command command_get_user_input();

#endif
