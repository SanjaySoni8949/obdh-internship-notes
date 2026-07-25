#ifndef COMMANDS_H
#define COMMANDS_H

void command_ping(int argc, char *argv[]);
void command_help(int argc, char *argv[]);
void command_status(int argc, char *argv[]);
void command_exit(int argc, char *argv[]);
void command_echo(int argc , char *argv[]);
void command_version(int argc,char*argv[]);


void register_commands(void);
#endif
