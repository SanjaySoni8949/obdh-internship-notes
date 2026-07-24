# Contributing

Thank you for your interest in contributing to the Generic Serial Command Shell.

This document provides guidelines for contributing to the project.

---

# Project Philosophy

The project emphasizes:

- Modularity
- Readability
- Simplicity
- Portability
- Reusability

Please keep these principles in mind when making changes.

---

# Before You Start

Before implementing new functionality:

- Read the documentation in the `docs/` directory.
- Understand the project architecture.
- Check whether a similar feature already exists.

---

# Adding a New Command

To add a new command:

1. Declare the command in `commands.h`

```c
void command_example(int argc, char *argv[]);
```

2. Implement the command in `commands.c`

```c
void command_example(int argc, char *argv[])
{
    printf("Example command\n");
}
```

3. Register the command

```c
command_register(
    "example",
    "Example command",
    "example",
    command_example
);
```

The command will automatically become available through the shell.

---

# Coding Style

Please follow these guidelines:

- Use meaningful names.
- Keep functions focused on one task.
- Validate user input.
- Add comments where necessary.
- Keep code modular.
- Avoid unnecessary global variables.

---

# Documentation

If your contribution introduces:

- a new command
- a new module
- a major architectural change

please update the relevant documentation in the `docs/` directory.

---

# Testing

Before submitting changes:

- Verify that the project builds successfully.
- Test both valid and invalid inputs.
- Ensure existing commands continue to work.
- Check that new commands appear in the `help` output.

---

# Reporting Issues

When reporting a bug, include:

- Operating system
- Compiler
- Steps to reproduce
- Expected behavior
- Actual behavior

---

# Suggestions

Feature requests and design improvements are always welcome.

If you have an idea that improves portability, modularity, or usability, feel free to open an issue or submit a pull request.

---

# Thank You

Thank you for helping improve the Generic Serial Command Shell.
