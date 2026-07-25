/*
 * tokenizer.h
 *
 * Public interface for the tokenizer module.
 *
 * Declares the tokenizer function used by other modules to
 * convert an input command string into argc/argv format.
 */




#ifndef TOKENIZER_H
#define TOKENIZER_H


# define max_arguments 10

/*
   input - Command string to tokenize.
   argc  - Pointer to the number of tokens found.
   argv  - Array of pointers to each token.
 */
void tokenizer( char * input , int *argc , char*argv[]);

#endif
