/*
 * main.c
 *
 * Entry point for the Serial Shell prototype.
 *
 * This program simulates a serial console using stdin.
 * Characters are processed one at a time, similar to how
 * a UART driver receives data in an embedded system.
 *
 * Features:
 *  - Character-by-character input
 *  - Backspace support
 *  - Enter detection
 *  - Leading space removal
 *  - Multiple space removal
 *  - Tab converted to space
 *  - Buffer overflow protection
 */





#include"commands.h"

#include"shell.h"



int main(void)
{
    shell_init();

    register_commands();

    while (1)
    {
        shell_process();
    }

    return 0;
}
