/*
 * commands.h
 *
 * Public interface for all shell commands.
 *
 * Declares:
 *  - Command callback functions.
 *  - The register_commands() function used during shell
 *    initialization to register all supported commands.
 */




#ifndef COMMANDS_H
#define COMMANDS_H

void command_ping(int argc, char *argv[]);
void command_help(int argc, char *argv[]);
void command_status(int argc, char *argv[]);
void command_exit(int argc, char *argv[]);

void register_commands(void);
#endif
