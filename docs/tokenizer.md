# Tokenizer

## Overview

The tokenizer is responsible for converting a raw command string entered by the user into individual tokens that can be processed by the Command Engine.

Instead of working with a single string, the shell converts the input into the standard C argument format (`argc` and `argv`).

This approach is similar to how the `main()` function receives command-line arguments in C programs.

---

# Responsibilities

The tokenizer is responsible for:

- Splitting user input into individual words
- Counting the number of arguments
- Creating the `argv` array
- Preparing the command for the Command Engine

The tokenizer is **not** responsible for:

- Reading user input
- Executing commands
- Validating commands

---

# Input

The tokenizer receives a complete command string.

Example:

```
echo Hello World
```

---

# Output

After tokenization:

```
argc = 3

argv[0] = "echo"
argv[1] = "Hello"
argv[2] = "World"
```

The Command Engine uses `argv[0]` to identify the command, while the remaining arguments are passed to the command callback.

---

# Why argc and argv?

Using `argc` and `argv` offers several advantages:

- Familiar C programming convention
- Easy to pass arguments to command handlers
- Supports commands with varying numbers of arguments
- Easy to extend for future commands

Example:

```
echo Hello World
```

becomes

```
argc = 3

argv[0] = "echo"
argv[1] = "Hello"
argv[2] = "World"
```

The `echo` command simply prints all arguments starting from `argv[1]`.

---

# Tokenization Process

The tokenizer follows these steps:

1. Receive the input string.
2. Initialize `argc` to zero.
3. Split the string using spaces as delimiters.
4. Store each token in `argv`.
5. Increment `argc` for each token.
6. Stop when no more tokens are found or the maximum number of arguments is reached.

---

# strtok()

The tokenizer uses the standard C library function `strtok()`.

First call:

```c
token = strtok(input, " ");
```

This returns the first token.

Subsequent calls:

```c
token = strtok(NULL, " ");
```

Passing `NULL` tells `strtok()` to continue scanning the same string from where it previously stopped.

---

# Example

Input:

```
status
```

Output:

```
argc = 1

argv[0] = "status"
```

---

Input:

```
help ping
```

Output:

```
argc = 2

argv[0] = "help"
argv[1] = "ping"
```

---

Input:

```
echo I love Embedded Systems
```

Output:

```
argc = 5

argv[0] = "echo"
argv[1] = "I"
argv[2] = "love"
argv[3] = "Embedded"
argv[4] = "Systems"
```

---

# Integration with the Command Engine

After tokenization, the shell calls:

```c
execute_command(argc, argv);
```

The Command Engine uses:

```c
argv[0]
```

to identify the command and passes all arguments to the command callback.

---

# Design Considerations

The tokenizer currently uses spaces as delimiters.

Future improvements may include:

- Quoted strings

```
echo "Hello World"
```

- Escape characters

```
echo Hello\ World
```

- Multiple delimiters

- Command piping

- Environment variable expansion

---

# Limitations

Current limitations include:

- Only space-separated arguments are supported.
- Quoted strings are not supported.
- Escape sequences are not supported.
- The maximum number of arguments is limited by `MAX_ARGUMENTS`.

These limitations keep the implementation simple and suitable for embedded systems.

---

# Summary

The tokenizer acts as the bridge between raw user input and the Command Engine.

By converting the input string into `argc` and `argv`, it provides a simple, efficient, and reusable interface for executing commands while remaining independent of the rest of the shell.
