/*
This files handle how the input can be send.
for now input send bu the keyboard later can be changed for UART etc.


*/




#include<stdio.h>
#include <string.h>

#include"command_engine.h"

int  main(void){

char command[50];
while(1){
    printf("> ");
    fgets(command,sizeof(command),stdin);
    command[strcspn(command, "\n")] = '\0'; // to remove the newline.

      if (command[0] == '\0')// check whether the string is empty or not if empty continue.
    {
        continue;
    }

    execute_command(command);
}


    return 0;
}
