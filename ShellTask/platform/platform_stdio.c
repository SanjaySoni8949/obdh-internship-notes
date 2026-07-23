

#include<stdio.h>
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
