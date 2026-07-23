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


typedef struct{
    const char*name;
    void(*handler)(int argc,char*argv[]);// handler is a pointer points to the function that returns the address the function that helps for mapping

}cmd_t;


#define MAX_COMMANDS 20

static cmd_t commands[MAX_COMMANDS];

static int command_count = 0;

void command_register(const char *name,
                      void (*handler)(int argc, char *argv[]))
{
    if (command_count >= MAX_COMMANDS)
    {
        printf("Error: Command table is full.\n");
        return;
    }

    commands[command_count].name = name;
    commands[command_count].handler = handler;

    command_count++;
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

    printf("Unknown command\n");
}
