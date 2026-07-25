/*
This file tells the rest of the project:

"If you want keyboard input or output, use these functions."
*/


#ifndef LINUX_CONSOLE_H
#define LINUX_CONSOLE_H


char shell_getchar(void);
void shell_putchar(char ch);
void shell_print(const char *str);

void shell_printf(const char *fmt, ...);//... this means that it can take variable number of argument.

#endif
