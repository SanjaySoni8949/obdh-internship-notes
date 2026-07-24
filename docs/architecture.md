# Architecture

## Overview

The Generic Serial Command Shell is divided into independent modules. Each module has a single responsibility, making the shell easy to maintain, extend, and port to different platforms.

---

## High-Level Architecture

```
                User
                  │
                  ▼
        Character Processor
                  │
                  ▼
           Command Buffer
                  │
                  ▼
             Tokenizer
            (argc / argv)
                  │
                  ▼
          Command Engine
                  │
      ┌───────────┴───────────┐
      ▼                       ▼
 Registered Commands   Unknown Command
      │
      ▼
 Command Callback
```

---

## Module Responsibilities

### shell.c

Responsible for:

- Reading characters one by one
- Handling backspace
- Ignoring leading spaces
- Detecting buffer overflow
- Calling the tokenizer
- Passing parsed commands to the command engine

---

### tokenizer.c

Responsible for converting a command string into tokens.

Input:

```
echo Hello World
```

Output:

```
argc = 3

argv[0] = "echo"
argv[1] = "Hello"
argv[2] = "World"
```

---

### command_engine.c

The command engine is responsible for:

- Registering commands
- Searching the command table
- Executing the correct callback
- Providing command information
- Listing available commands

The command engine never knows what a command actually does.

---

### commands.c

Contains the implementation of all commands.

Examples:

- ping
- help
- status
- version
- echo
- exit

Each command is implemented as an independent callback.

---

### platform_stdio.c

Provides platform-specific services.

Desktop implementation:

- shell_getchar()
- shell_putchar()

Future embedded implementation:

- UART_Read()
- UART_Write()

The rest of the shell remains unchanged.

---

## Execution Flow

When the user types

```
echo Hello World
```

the following sequence occurs:

```
Keyboard
    │
    ▼
shell_getchar()
    │
    ▼
shell.c
    │
    ▼
tokenizer()
    │
    ▼
argc = 3

argv[0] = echo
argv[1] = Hello
argv[2] = World
    │
    ▼
execute_command()
    │
    ▼
command_echo()
```

---

## Design Principles

The shell follows several software engineering principles.

### Modularity

Each source file has a single responsibility.

### Platform Independence

Only the platform layer depends on the operating system or hardware.

### Extensibility

Adding a new command does not require modifying the command engine.

### Separation of Concerns

Input processing, parsing, command lookup, and command execution are handled by different modules.

---

## Future Architecture

The desktop implementation will eventually be replaced with a UART backend.

```
Keyboard
    │
shell_getchar()
```

↓

```
UART
    │
shell_getchar()
```

No other module requires modification.
