# Commands

## Overview

This document describes all commands currently supported by the Generic Serial Command Shell.

Each command consists of:

- Command name
- Description
- Usage
- Example

---

# Command Summary

| Command | Description |
|----------|-------------|
| help | Display available commands or detailed help for a specific command |
| ping | Check shell connectivity |
| echo | Print text to the console |
| status | Display shell status |
| version | Display shell version |
| exit | Exit the shell |
| quit | Alias for `exit` |
| ? | Alias for `help` |

---

# help

## Description

Displays all registered commands.

If a command name is provided, detailed information about that command is displayed.

## Usage

```text
help
```

or

```text
help <command>
```

## Examples

```text
> help
```

Output

```text
Available Commands

help
ping
echo
status
version
exit
```

Detailed help

```text
> help ping
```

Output

```text
Command     : ping
Description : Check shell connectivity
Usage       : ping
```

---

# ping

## Description

Checks whether the shell is responsive.

Useful for testing command execution.

## Usage

```text
ping
```

## Example

```text
> ping
```

Output

```text
PONG
```

---

# echo

## Description

Prints all supplied arguments.

Useful for testing the tokenizer and argument passing.

## Usage

```text
echo <text>
```

## Examples

```text
> echo Hello World
```

Output

```text
Hello World
```

---

# status

## Description

Displays basic shell information.

The exact output depends on the implementation.

## Usage

```text
status
```

## Example

```text
> status
```

Example Output

```text
Shell Status : Running
Registered Commands : 7
```

---

# version

## Description

Displays the current shell version.

## Usage

```text
version
```

## Example

```text
> version
```

Example Output

```text
Generic Serial Command Shell
Version : 1.0
```

---

# exit

## Description

Terminates the shell.

## Usage

```text
exit
```

## Example

```text
> exit
```

Output

```text
Exiting shell...
```

---

# quit

## Description

Alias for the `exit` command.

## Usage

```text
quit
```

## Example

```text
> quit
```

Output

```text
Exiting shell...
```

---

# ?

## Description

Alias for the `help` command.

## Usage

```text
?
```

## Example

```text
> ?
```

Output

```text
Available Commands

help
ping
echo
status
version
exit
```

---

# Error Messages

If an unknown command is entered, the shell displays an error message.

Example

```text
> abc
```

Output

```text
Unknown command: abc

Type "help" to list available commands.
```

---

# Notes

- Command names are currently case-sensitive.
- Arguments are separated by spaces.
- Commands are executed after the Enter key is pressed.
- The first argument (`argv[0]`) is always interpreted as the command name.

---

# Summary

The Generic Serial Command Shell provides a small set of modular commands for testing the shell architecture and demonstrating the functionality of the Command Engine. New commands can be added easily through the command registration mechanism without modifying the core shell implementation.
