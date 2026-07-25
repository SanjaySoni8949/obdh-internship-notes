/*
 * command_engine.c
 *
 * Implements the shell command engine.
 *
 * Responsibilities:
 *  - Maintains the command registry.
 *  - Registers new commands using command_register().
 *  - Searches the registered command table.
 *  - Matches the user command with the corresponding callback.
 *  - Executes the appropriate command function.
 *
 * The command engine is independent of individual commands.
 * It only knows how to register and dispatch commands.
 */















#include<stdio.h>
 
#include <string.h>
#include"command_engine.h"
#include"tokenizer.h"
#include"commands.h"
#include "linux_console.h"

#define MAX_COMMANDS 20

static cmd_t commands[MAX_COMMANDS];

static int command_count = 0;

void command_register(const char *name,const char*description,const char * usage,
                      void (*handler)(int argc, char *argv[]))
{
    if (command_count >= MAX_COMMANDS)
    {
        shell_print("Error: Command table is full.\n");
        return;
    }

    commands[command_count].name = name;
    commands[command_count].description=description;
    commands[command_count].usage=usage;
    commands[command_count].handler = handler;

    command_count++;
}
void command_list(void)
{
    shell_print("Available Commands:\n\n");

    for (int i = 0; i < command_count; i++)
    {
        shell_printf("%-10s - %s\n",
               commands[i].name,
               commands[i].description);
    }
}
const cmd_t *command_find(const char *name)
{
    for (int i = 0; i < command_count; i++)
    {
        if (strcmp(name, commands[i].name) == 0)
        {
            return &commands[i];
        }
    }

    return NULL;
}

void execute_command(int argc, char *argv[])
{
    if (argc == 0)
    {
        return;
    }


    for (int i = 0; i < command_count; i++)
    {
        if (strcmp(argv[0], commands[i].name) == 0)
        {
            commands[i].handler(argc, argv);
            return;
        }
    }

    shell_print("Unknown command:\n");
    shell_print("Type 'help' to see available commands.\n");

 
}

   int command_get_count(void){
        return command_count;
    }
