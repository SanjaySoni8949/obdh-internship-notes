
/*
 * commands.c
 *
 * Implements all shell command callback functions.
 *
 * Responsibilities:
 *  - Implements the behavior of each supported shell command.
 *  - Registers available commands with the command engine.
 *
 * Each callback receives argc and argv, allowing commands to
 * process user-supplied arguments.
 *
 * Examples:
 *      ping
 *      help
 *      status
 *      exit
 */



#include<stdio.h>
#include <stdlib.h>   
#include"command_engine.h"
#include"commands.h"


void command_ping(int argc , char*argv[]){
    (void)argc;//these are unused parameter.
    (void)argv;//
printf("PONG\n");
}

void command_help(int argc , char*argv[])
{
    (void)argc;
    (void)argv;
    printf("Available Commands:\n");
    printf("ping - Ping\n");
    printf("help - Help\n");
    printf("status - Status\n");
    printf("exit - Exit\n");
}


void command_status(int argc , char*argv[]){
    (void)argc;
    (void)argv;
printf("System Status:Ok\n");
}

void command_exit(int argc , char*argv[]){
    (void)argc;
    (void)argv;
    printf("Exiting shell...\n");

    exit(0);// this function is standard library function (stdlib) used to exit the shell.
}
void register_commands(void)
{
    command_register("ping", command_ping);
    command_register("help", command_help);
    command_register("status", command_status);
    command_register("exit", command_exit);
}
