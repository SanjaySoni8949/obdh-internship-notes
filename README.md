# Generic Command Shell

A modular and portable command-line shell written in C for embedded systems.

This project was developed as a desktop prototype for a serial command shell that can later be integrated into embedded platforms such as the MSP430 running FreeRTOS. The shell is designed with modularity in mind, separating command parsing, command execution, and platform-specific input/output.

---

# Features

- Character-by-character command input
- Backspace support
- Ignore leading and repeated spaces
- Command tokenizer (`argc` / `argv`)
- Dynamic command registration
- Generic command engine
- Command descriptions and usage information
- `help` and `help <command>`
- `echo` command
- `version` command
- Command aliases (`quit`, `?`)
- Modular architecture
- Platform abstraction layer

---

# Project Structure

```
.
├── main.c
├── shell.c
├── shell.h
├── tokenizer.c
├── tokenizer.h
├── command_engine.c
├── command_engine.h
├── commands.c
├── commands.h
├── platform.h
├── platform_stdio.c
└── README.md
```

---

# Architecture

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
      ┌─────────────┴─────────────┐
      ▼                           ▼
Registered Commands        Unknown Command
      │
      ▼
Command Handler
```

---

# Command Flow

For example, when the user enters:

```
echo Hello World
```

The tokenizer converts the input into:

```
argc = 3

argv[0] = "echo"
argv[1] = "Hello"
argv[2] = "World"
```

The command engine searches for `"echo"` in the command table and executes the corresponding handler.

---

# Available Commands

| Command | Description |
|----------|-------------|
| help | Display all commands |
| help \<command\> | Show detailed help for a command |
| ping | Test shell connectivity |
| status | Display shell status |
| version | Display shell version |
| echo | Print text to the console |
| exit | Exit the shell |
| quit | Alias for exit |
| ? | Alias for help |

---

# Adding a New Command

Adding a new command requires three simple steps.

### 1. Declare the command

```c
void command_led(int argc, char *argv[]);
```

### 2. Implement the handler

```c
void command_led(int argc, char *argv[])
{
    printf("LED command executed\n");
}
```

### 3. Register the command

```c
command_register(
    "led",
    "Control LED",
    "led <on|off>",
    command_led
);
```

No changes to the command engine are required.

---

# Platform Abstraction

The shell is independent of the underlying hardware.

Desktop version:

```
Keyboard
    │
shell_getchar()
    │
Shell
    │
Console
```

Embedded version:

```
UART
   │
shell_getchar()
   │
Shell
   │
Serial Terminal
```

Only the platform layer must be modified when porting to a different target.

---

# Building

Compile using GCC:

```bash
gcc *.c -o shell
```

Run:

```bash
./shell
```

---

# Example Session

```
> help

Available Commands:

ping       - Check shell connectivity
help       - Show available commands
status     - Display shell status
version    - Display shell version
echo       - Print text
exit       - Exit shell

> ping
PONG

> echo Hello World
Hello World

> help echo

Command     : echo
Description : Print text to the console
Usage       : echo <text>

> version

Shell Version : 1.0
Platform      : Desktop Prototype
```

---

# Future Improvements

- Command history
- Auto-completion
- UART backend
- FreeRTOS integration
- MSP430 support
- Unit tests
- Configuration file

---

# Author

Sanjay Soni

Developed as part of an embedded systems learning project and designed to evolve into a reusable serial command shell for embedded platforms.
