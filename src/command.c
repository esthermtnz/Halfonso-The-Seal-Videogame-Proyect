/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */
/*Defines some macros and libraries*/
#include <stdio.h>
#include <strings.h>
#include "command.h"
/**
 * @brief maximum command size of the command
 */
#define CMD_LENGHT 30
/**
 * @brief Defines the name of the commands and the abbreviations
 */
char *cmd_to_str[N_CMD]
                /*Defines the name of the commands and the abbreviations*/
                [N_CMDT] = {{"", "No command"},
                            {"", "Unknown"},
                            {"e", "Exit"},
                            {"t", "Take"},
                            {"d", "Drop"},
                            {"m", "Move"},
                            {"a", "Attack"},
                            {"ton", "TurnOn"},
                            {"toff", "TurnOff"},
                            {"o", "Open"},
                            {"i", "Inspect"},
                            {"s", "Save"},
                            {"l", "Load"}};

/*Its scans the command bar and depending on the command introduces it keeps reading or not*/
T_Command command_get_user_input()
{
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;

  if (scanf("%s", input) > 0)
  {
    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
  }

  return cmd;
}
