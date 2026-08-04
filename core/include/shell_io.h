/*
 * shell_io.h
 *
 * Platform-independent I/O interface for the command shell.
 *
 * Each supported platform (Linux, FreeRTOS, etc.) must provide
 * implementations of the functions declared in this file.
 */

#ifndef SHELL_IO_H
#define SHELL_IO_H

/**
 * @brief Read a single character from the input source.
 *
 * @return Character read from the input stream.
 */
char shell_getchar(void);

/**
 * @brief Write a single character to the output.
 *
 * @param ch Character to transmit.
 */
void shell_putchar(char ch);

/**
 * @brief Print a null-terminated string.
 *
 * @param str String to print.
 */
void shell_print(const char *str);

/**
 * @brief Print formatted output.
 *
 * Behaves similarly to printf(), but uses the platform-specific
 * output implementation.
 *
 * @param fmt Format string.
 * @param ... Variable arguments.
 */
void shell_printf(const char *fmt, ...);

#endif /* SHELL_IO_H */
