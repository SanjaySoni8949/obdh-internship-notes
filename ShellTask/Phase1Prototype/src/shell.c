#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "platform.h"
#include "tokenizer.h"
#include "command_engine.h"
#include"shell_config.h"

#define SHELL_PROMPT "> "

void shell_run(void){
    char command[MAX_COMMAND_LENGTH];
    char ch;
    int index;

    while (1)
    {
        printf(SHELL_PROMPT);

        index = 0;

        while (1)
        {
            ch = shell_getchar();

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
                while ((ch = shell_getchar()) != '\n' && ch != EOF);// ch=getchar()=!'\n' will one input at  a time 
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
char *argv[MAX_ARGUMENTS];

tokenizer(command, &argc, argv);

execute_command(argc, argv);
    }

}

