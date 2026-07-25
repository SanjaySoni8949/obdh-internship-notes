#include<stdio.h>
#include<stdarg.h>
#include"platform.h"


char shell_getchar(void){
    return getchar();
}

void shell_putchar(char  ch){
    putchar(ch);
}
void shell_print(const char *str){
    while(*str){
        shell_putchar(*str++);
    }
}
void shell_printf(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    vprintf(fmt, args);

    va_end(args);
}
