/*
 * command_engine.h
 *
 * Public interface for the command engine.
 *
 * Declares functions used to:
 *  - Register commands.
 *  - Execute commands.
 *  - Manage the shell command registry.
 *
 * Other modules interact with the command engine only through
 * the functions declared in this header.
 */





#ifndef COMMAND_ENGINE_H
#define COMMAND_ENGINE_H

void execute_command(int argc, char *argv[]);

void command_register(const char *name, void (*handler)(int argc, char *argv[]));
void command_unregister_all(void);
#endif
