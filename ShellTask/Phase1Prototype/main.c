#include <stdio.h>
#include <stdint.h>

#include "command_engine.h"

int main(void)
{
    /* Stores the Command ID entered by the user */
    uint8_t cmd_id;

    while (1)
    {
        printf("> ");

        /* Read the Command ID in hexadecimal format.
           Example input: 01 */
        if (scanf("%hhx", &cmd_id) != 1)
        {
            printf("Invalid Command ID!\n");

            while (getchar() != '\n');

            continue;
        }

        /* Send the Command ID to the command engine */
        execute_command(cmd_id);
    }

    return 0;
}
