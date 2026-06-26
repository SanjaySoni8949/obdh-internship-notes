/*  
This file contain the mapping of the user input to the define function to execute

file contains the execute command function to check whether the user input command is a known command or not

*/







#include<stdio.h>
 
#include <string.h>
#include"command_engine.h"



typedef struct{
    char*input;
    void(*handler)(void);// handler is a pointer points to the function that returns the address the function that helps for mapping

}cmd_t;


cmd_t commands[]={
    {"ping",command_ping},
    {"help",command_help},
    {"status",command_status},
    {"exit",command_exit}


};

void execute_command(char *cmd){
    int number_commands=sizeof(commands)/sizeof(commands[0]);
for(int i =0 ; i<number_commands;i++){
if(strcmp(cmd,commands[i].input)==0){ // strcmp is a function to comapare two string and if two string are equal it returns 0.
    commands[i].handler();
    return;
}


}

 printf("Unknown Command!\n");


}
