#ifndef SHELL_IO_H
#define SHELL_IO_H

char shell_getchar(void);
void shell_putchar(char ch);
void shell_print(const char *str);
void shell_printf(const char *fmt, ...);

#endif
