/*
This file contains all the commands performed by the shell.

*/




#include<stdio.h>
#include <stdlib.h>   
#include"command_engine.h"



void command_ping(void){
printf("PONG");
}

void command_help(void)
{
    printf("Available Commands:\n");
    printf("0x01 - Ping\n");
    printf("0x02 - Help\n");
    printf("0x03 - Status\n");
    printf("0x04 - Exit\n");
}

void command_status(void){
printf("System Status:Ok");
}

void command_exit(void){
    printf("Exiting shell...");

    exit(0);// this function is standard library function (stdlib) used to exit the shell.
}



