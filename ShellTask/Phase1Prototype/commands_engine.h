/*
 * command_engine.h
 *
 * Header file for the command engine.
 * It contains command IDs, function declarations,
 * and the command engine interface.
 */

#ifndef COMMAND_ENGINE_H
#define COMMAND_ENGINE_H

#include <stdint.h>

/* Command IDs */

typedef enum
{
    CMD_PING   = 0x01,
    CMD_HELP   = 0x02,
    CMD_STATUS = 0x03,
    CMD_EXIT   = 0x04

} command_id_t;


/* Command Handler Prototypes */

void command_ping(void);

void command_help(void);

void command_status(void);

void command_exit(void);


/* Command Engine */

void execute_command(uint8_t cmd_id);

#endif
