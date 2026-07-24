# Command Engine

## Overview

The Command Engine is the core component of the Generic Serial Command Shell.

Its responsibility is to maintain a list of available commands, search for commands entered by the user, and execute the corresponding callback function.

The Command Engine does **not** implement any command logic. Instead, it acts as a dispatcher between the user input and the command implementation.

---

# Responsibilities

The Command Engine is responsible for:

- Registering commands
- Storing command information
- Looking up commands
- Executing command callbacks
- Listing available commands
- Providing command information for the `help` command

The Command Engine is **not** responsible for:

- Reading user input
- Parsing commands
- Implementing command functionality
- Platform-specific input/output

These responsibilities belong to other modules.

---

# Command Registration

Every command must be registered before it can be executed.

Registration is performed during system initialization.

Example:

```c
command_register(
    "ping",
    "Check shell connectivity",
    "ping",
    command_ping
);
```

Each registration adds one entry to the internal command table.

---

# Command Structure

Every registered command is represented using the following structure.

```c
typedef struct
{
    const char *name;
    const char *description;
    const char *usage;
    void (*handler)(int argc, char *argv[]);
} cmd_t;
```

Each field has a specific purpose.

| Field | Purpose |
|--------|----------|
| name | Command entered by the user |
| description | Short explanation shown by `help` |
| usage | Correct syntax of the command |
| handler | Function executed when the command is found |

---

# Dynamic Registration

Commands are stored inside an internal command table.

```
Command Table

+--------------------------------------------+
| ping     → command_ping()                  |
| help     → command_help()                  |
| status   → command_status()                |
| echo     → command_echo()                  |
| version  → command_version()               |
| exit     → command_exit()                  |
+--------------------------------------------+
```

Unlike a large `if-else` chain, new commands can be added without modifying the Command Engine.

Only a new registration call is required.

---

# Command Lookup

When the user enters a command, the tokenizer produces:

```
argc = 3

argv[0] = "echo"
argv[1] = "Hello"
argv[2] = "World"
```

The Command Engine searches for:

```
argv[0]
```

which is

```
echo
```

using the `command_find()` function.

If a matching command exists, its information is returned.

Otherwise, `NULL` is returned.

---

# Command Execution

After a successful lookup, the Command Engine executes the command callback.

```
User Input

↓

Tokenizer

↓

argv[0] = "ping"

↓

command_find()

↓

command_ping()
```

Notice that the Command Engine never knows what the callback actually does.

Its only responsibility is to invoke the correct function.

---

# Function Pointers

The Command Engine uses function pointers to connect command names with their implementations.

Example:

```c
void (*handler)(int argc, char *argv[]);
```

This pointer stores the address of a command function.

Example:

```
command_ping
        │
        ▼
+--------------------+
| Function Address   |
+--------------------+
```

When a command is found, the engine executes

```c
handler(argc, argv);
```

without knowing which function it points to.

This makes the Command Engine generic and reusable.

---

# Command Lifecycle

The complete lifecycle of a command is shown below.

```
Developer

↓

Create callback

↓

Register command

↓

Store inside command table

↓

User enters command

↓

Tokenizer

↓

Command lookup

↓

Execute callback
```

---

# Listing Commands

The `help` command uses the Command Engine to retrieve available commands.

Instead of maintaining its own list, it calls:

```
command_list()
```

The Command Engine prints every registered command together with its description.

This keeps command information centralized.

---

# Error Handling

If a command cannot be found, the Command Engine reports an unknown command.

Example:

```
> hello

Unknown command: hello

Type "help" to list available commands.
```

---

# Advantages of This Design

Compared to a large `if-else` chain, the Command Engine provides several advantages.

## Scalability

Adding new commands requires no changes to the lookup logic.

---

## Maintainability

Each command is implemented independently.

---

## Reusability

The Command Engine can be reused in different projects.

---

## Extensibility

Additional features such as:

- aliases
- permissions
- auto-completion
- command history

can be implemented without redesigning the engine.

---

# Summary

The Command Engine acts as the central dispatcher of the shell.

It stores command information, searches for commands entered by the user, and invokes the corresponding callback function using function pointers.

Because command execution is separated from command implementation, the engine remains generic, modular, and easy to extend.
