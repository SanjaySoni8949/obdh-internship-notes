#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "shell_io.h"
#include "tokenizer.h"
#include "command_engine.h"
#include "shell_config.h"

#define SHELL_PROMPT "> "

static char command[MAX_COMMAND_LENGTH];
static int index = 0;


/*
 * Legacy convenience wrapper.
 *
 * Applications are encouraged to call shell_process()
 * from their own main loop instead of using shell_run().
 */
void shell_run(void)
{
    while (1)
    {
        shell_process();
    }
}

void shell_process(void)
{
    char ch;

    shell_print(SHELL_PROMPT);

    index = 0;

    while (1)
    {
        ch = shell_getchar();

        /* Convert TAB into a normal space */
        if (ch == '\t')
        {
            ch = ' ';
        }

        shell_process_char(ch);

        /* Handle Backspace */
        if (ch == '\b' || ch == 127)
        {
            if (index > 0)
            {
                index--;
                shell_putchar('\b');
                shell_putchar(' ');
                shell_putchar('\b');
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
            shell_print("\nError: Command too long.\n");

            while ((ch = shell_getchar()) != '\n' && ch != EOF)
                ;

            index = 0;
            break;
        }

        /* Store character */
        command[index++] = ch;
    }

    /* Ignore empty commands */
    if (command[0] == '\0')
    {
        return;
    }

    shell_process_input(command);
}

void shell_process_input(char *input)
{
    int argc;
    char *argv[MAX_ARGUMENTS];

    tokenizer(input, &argc, argv);

    execute_command(argc, argv);
}

void shell_process_char(char ch)
{
    (void)ch;
}

void shell_init(void)
{
    /* Reserved for future initialization */
}
