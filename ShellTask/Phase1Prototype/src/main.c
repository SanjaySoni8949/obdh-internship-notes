/*
 * main.c
 *
 * Entry point of the shell application.
 *
 * Responsibilities:
 *  - Initializes the shell.
 *  - Registers all available commands.
 *  - Reads user input character-by-character.
 *  - Handles basic line editing (backspace, tabs, spaces, etc.).
 *  - Stores the input into a command buffer.
 *  - Invokes the tokenizer to split the command into arguments.
 *  - Passes the tokenized command to the command engine for execution.
 *
 * This file is responsible only for user interaction and
 * coordinating the overall shell workflow.
 */

#include <stdio.h>

#include "command_engine.h"
#include"tokenizer.h"
#include"commands.h"

#define MAX_COMMAND_LENGTH 50
#define SHELL_PROMPT "> "

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
     register_commands();
    char ch;
    int index;

    while (1)
    {
        printf(SHELL_PROMPT);

        index = 0;

        while (1)
        {
            ch = getchar();

            /* Convert TAB into a normal space */
            if (ch == '\t')
            {
                ch = ' ';
            }

            /* Handle Backspace */
            if (ch == '\b' || ch == 127)// different terminal has different ascii value and

                                         //c represntation like for backspace=\b and for delete=127
            {
                if (index > 0)
                {
                    index--;
                    printf("\b \b");
                }

                continue;
            }

            /* Handle Enter */
            if (ch == '\n')
            {
                command[index] = '\0';
                break;
            }

            /* Ignore leading spaces */
            if (ch == ' ' && index == 0)
            {
                continue;
            }

            /* Ignore repeated spaces */
            if (ch == ' ' && command[index - 1] == ' ')
            {
                continue;
            }

            /* Check buffer overflow */
            if (index >= MAX_COMMAND_LENGTH - 1)
            {
                printf("\nError: Command too long.\n");

                /* Discard remaining characters */
                while ((ch = getchar()) != '\n' && ch != EOF);// ch=getchar()=!'\n' will one input at  a time 
                                                              // and will check if it is enter if not continue looping
                                                             //EOF=End of File means stdin closes or 
                                                             // input stream ends.
                index = 0;
                break;
             }

               /* Store character */
               command[index++] = ch;
              }

          /* Ignore empty commands */
               if (command[0] == '\0')
        {
            continue;
        }

        /* Execute the completed command */
               int argc;
               char *argv[max_arguments];

               tokenizer(command, &argc, argv);

               execute_command(argc, argv);
    }

                 return 0;
}
