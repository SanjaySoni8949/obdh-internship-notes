/*
 * shell.h
 *
 * Public interface for the generic command shell library.
 *
 * This module provides the APIs required to run the shell and
 * process user input.
 */

#ifndef SHELL_H
#define SHELL_H

/**
 * @brief Start the interactive shell.
 *
 * This function starts the shell loop and continuously reads
 * input from the configured platform until the application exits.
 */
void shell_run(void);

/**
 * @brief Process a single input character.
 *
 * Reserved for future event-driven implementations where
 * characters are processed one at a time (e.g. UART interrupts).
 *
 * @param ch Input character.
 */
void shell_process_char(char ch);

/**
 * @brief Process a complete command line.
 *
 * Tokenizes the input string and dispatches the corresponding
 * registered command.
 *
 * @param input Null-terminated command string.
 */
void shell_process_input(char *input);

#endif /* SHELL_H */
