# Developer Guide

## Overview

This guide explains how to extend the Generic Serial Command Shell by adding new commands and modifying existing functionality.

The shell is designed to be modular. Most extensions can be implemented without changing the core components such as the tokenizer or command engine.

---

# Project Structure

```
project/
│
├── commands.c
├── commands.h
├── command_engine.c
├── command_engine.h
├── shell.c
├── tokenizer.c
├── platform_stdio.c
│
├── README.md
│
└── docs/
```

---

# Adding a New Command

Adding a new command involves three simple steps.

## Step 1 — Declare the Command

In `commands.h`, declare the command function.

```c
void command_led(int argc, char *argv[]);
```

---

## Step 2 — Implement the Command

In `commands.c`, implement the function.

```c
void command_led(int argc, char *argv[])
{
    printf("LED command executed\n");
}
```

The command can access its arguments through `argc` and `argv`.

Example:

```
led on
```

Results in:

```
argc = 2

argv[0] = "led"
argv[1] = "on"
```

---

## Step 3 — Register the Command

Register the command during initialization.

```c
command_register(
    "led",
    "Control the LED",
    "led <on|off>",
    command_led
);
```

The command is now available to the shell.

---

# Command Handler Guidelines

Each command should:

- Perform one task
- Validate its arguments
- Display helpful error messages
- Return control to the shell after execution

Example:

```c
void command_led(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: led <on|off>\n");
        return;
    }

    if(strcmp(argv[1], "on") == 0)
    {
        printf("LED ON\n");
    }
    else if(strcmp(argv[1], "off") == 0)
    {
        printf("LED OFF\n");
    }
    else
    {
        printf("Invalid option\n");
    }
}
```

---

# Adding an Alias

An alias is created by registering another name with the same handler.

Example:

```c
command_register(
    "quit",
    "Alias for exit",
    "quit",
    command_exit
);
```

No additional implementation is required.

---

# Accessing Arguments

The tokenizer provides commands with:

```c
argc
```

Number of arguments.

```c
argv
```

Array of argument strings.

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

---

# Error Handling

Commands should detect invalid usage and provide clear feedback.

Example:

```text
> led

Usage: led <on|off>
```

Avoid allowing commands to fail silently.

---

# Coding Guidelines

To keep the project consistent:

- Use meaningful function names.
- Keep functions focused on a single responsibility.
- Validate all user input.
- Avoid modifying global state unless necessary.
- Keep command handlers short and readable.

---

# Testing New Commands

Before adding a command to the project, verify that:

- The command is registered successfully.
- The command appears in the `help` output.
- Valid input produces the expected result.
- Invalid input displays a helpful error message.
- No existing commands are affected.

---

# Common Mistakes

## Forgetting to Register the Command

If a command is implemented but not registered, the shell cannot execute it.

---

## Incorrect Usage String

Ensure that the usage string accurately reflects the expected syntax.

---

## Missing Argument Validation

Always check `argc` before accessing `argv`.

Example:

```c
if(argc < 2)
{
    printf("Missing argument\n");
    return;
}
```

---

## Modifying the Command Engine

Most new features do not require changes to the Command Engine.

Instead, add a new command and register it.

---

# Best Practices

- Keep commands independent.
- Reuse helper functions where appropriate.
- Provide concise descriptions and usage strings.
- Use aliases only when they improve usability.
- Update the documentation whenever new commands are added.

---

# Summary

The Generic Serial Command Shell is designed to be extended through command registration rather than by modifying the core engine.

By following the steps in this guide, developers can add new commands while preserving the modular architecture and keeping the shell easy to maintain.
