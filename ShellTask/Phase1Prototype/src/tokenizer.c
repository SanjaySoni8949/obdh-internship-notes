
/*
 * tokenizer.c
 *
 * Implements the shell tokenizer.
 *
 * Responsibilities:
 *  - Splits the input command line into individual tokens.
 *  - Converts a command string into argc/argv format.
 *  - Separates the command name from its arguments.
 *
 * Example:
 *      Input:
 *          "echo Hello World"
 *
 *      Output:
 *          argc = 3
 *          argv[0] = "echo"
 *          argv[1] = "Hello"
 *          argv[2] = "World"
 *
 * The tokenizer allows commands to receive arguments in a
 * standard command-line format.
 */




#include<string.h>
#include"tokenizer.h"


void tokenizer( char * input , int*argc , char * argv[]){


char * token;
*argc=0;


token=strtok( input ," ");//strtok=string token( char input , const dilimeter)  here dilimeter is space.
                          //dilimeter=A delimiter is simply a character that separates pieces of data.

while(token!=NULL && *argc<max_arguments){
    argv[*argc]=token;
    (*argc)++;

    token=strtok(input," ");
}

}
