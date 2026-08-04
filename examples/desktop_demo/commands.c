
/*
This file contains all the commands performed by the shell.

*/




#include<stdio.h>
#include <stdlib.h>   
#include"command_engine.h"
#include"commands.h"
#include "linux_console.h"
#include"shell_config.h"
#include"tokenizer.h"

void command_ping(int argc , char*argv[]){
    (void)argc;//these are unused parameter.
    (void)argv;//
shell_print("PONG\n");
}

void command_help(int argc, char *argv[])
{

    if (argc == 1)
    {
        command_list();
        return;
    }

    const cmd_t *cmd = command_find(argv[1]);

    if (cmd == NULL)
    {
        shell_printf("No help available for '%s'\n", argv[1]);
        return;
    }

    shell_printf("Command     : %s\n", cmd->name);
     shell_printf("Description : %s\n", cmd->description);
     shell_printf("Usage       : %s\n", cmd->usage);
}


void command_status(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    printf("========== Shell Status ==========\n");
    printf("Platform            : Desktop Prototype\n");
    printf("Shell Version       : 1.0\n");
    printf("Registered Commands : %d\n", command_get_count());
    printf("Max Command Length  : %d\n", MAX_COMMAND_LENGTH);
    printf("Max Arguments       : %d\n", MAX_ARGUMENTS);
    printf("==================================\n");
}
void command_exit(int argc , char*argv[]){
    (void)argc;
    (void)argv;
     shell_print("Exiting shell...\n");

    exit(0);// this function is standard library function (stdlib) used to exit the shell.
}
void command_echo(int argc, char *argv[])
{
    if (argc == 1)
    {
         shell_print("\n");
        return;
    }

    for (int i = 1; i < argc; i++)
    {
         shell_printf("%s", argv[i]);

        if (i < argc - 1)
        {
             shell_print(" ");
        }
    }

     shell_print("\n");
}

void command_version(int argc,char*argv[]){
    (void)argc;
    (void)argv;
     printf("Shell Version : 1.0\n");
    printf("Platform      : Desktop Prototype\n");
    printf("Build         : Generic Command Shell\n");
}
void register_commands(void)
{
    command_register("ping", "Check shell connectivity"," ping", command_ping);
    command_register("help", "Show available commands", "help [command]",command_help);
    command_register("status","Display system status","status", command_status);
    command_register("exit","Exit the shell","exit", command_exit);
    command_register("echo","Print text to the console","echo<text>",command_echo);
    command_register("quit","Alias for exit","quit",command_exit);
    command_register("?","Aliase for help","?",command_help);
    command_register("version","display shell version","version",command_version);
}
