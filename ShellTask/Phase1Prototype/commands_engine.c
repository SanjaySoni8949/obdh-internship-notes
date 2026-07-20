/*  
This file contain the mapping of the user input to the define function to execute

file contains the execute command function to check whether the user input command is a known command or not

*/







#include<stdio.h>
 
#include <string.h>
#include"command_engine.h"


typedef struct
{
    uint8_t command_id;
    void (*handler)(void);// handler is a pointer points to the function that returns the address the function that helps for mapping

} cmd_t;



cmd_t commands[] =
{
    {CMD_PING,   command_ping},
    {CMD_HELP,   command_help},
    {CMD_STATUS, command_status},
    {CMD_EXIT,   command_exit}
};
void execute_command(uint8_t cmd_id)
{
    int number_commands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < number_commands; i++)
    {
        if (cmd_id == commands[i].command_id)
        {
            commands[i].handler();
            return;
        }
    }

    printf("Unknown Command ID: 0x%02X\n", cmd_id);
}


