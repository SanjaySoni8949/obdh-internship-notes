#include<string.h>
#include"tokenizer.h"


void tokenizer( char * input , int*argc , char * argv[]){


char * token;
*argc=0;


token=strtok( input ," ");//strtok=string token( char input , const dilimeter)  here dilimeter is space.
                          //dilimeter=A delimiter is simply a character that separates pieces of data.

while (token != NULL && *argc < MAX_ARGUMENTS)
{
    argv[*argc] = token;
    (*argc)++;

    token = strtok(NULL, " ");
}
}
