/*
 * tokenizer.h
 *
 * Tokenizer interface for the generic command shell.
 *
 * This module splits a command line into individual arguments
 * that can be passed to the command engine.
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

/**
 * @brief Tokenize a command line.
 *
 * Splits the input string into whitespace-separated arguments.
 * The input string is modified in-place by inserting null
 * terminators ('\0') between tokens.
 *
 * Example:
 *   Input : "echo hello world"
 *
 *   argc = 3
 *   argv[0] = "echo"
 *   argv[1] = "hello"
 *   argv[2] = "world"
 *
 * @param input Command line to tokenize.
 * @param argc Pointer to the argument count.
 * @param argv Array that receives pointers to each argument.
 */
void tokenizer(char *input, int *argc, char *argv[]);

#endif /* TOKENIZER_H */
