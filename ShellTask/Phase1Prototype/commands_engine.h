/*
This file is the header file that contains the commands .
and this file can be used by different file to access the command by just including it (  #inlcude"commands_engine.h")
*/



#ifndef COMMANDS_ENGINE_H
#define COMMANDS_ENGINE_H

void command_ping(void);

void command_help(void);


void command_status(void);

void command_exit(void);


void execute_command(char *cmd);
#endif
