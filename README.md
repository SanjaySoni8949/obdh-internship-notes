# obdh-internship-notes





# OBDH Command Shell Prototype

## Overview

This repository contains my prototype implementation of a simple command shell developed as part of my OBDH internship learning process.

The purpose of this project is to understand the architecture of a generic command engine before integrating it with the actual OBDH firmware.

The current implementation runs on a PC using the standard input (`stdin`) to simulate a serial console.

---

## Objectives

- Learn Embedded C programming.
- Understand command engine architecture.
- Learn function pointers in C.
- Build a modular command shell.
- Prepare for UART-based command processing.

---

## Features

- Console-based command shell.
- Command lookup using a command table.
- Function pointer-based command execution.
- Basic commands:
  - ping
  - help
  - status
  - exit

---

## Project Structure

```
main.c
command_engine.c
command_engine.h
commands.c
commands.h
```

### main.c

Reads user input from the console and passes commands to the command engine.

### command_engine.c

Searches the command table and executes the matching command.

### commands.c

Contains the implementation of each command.

---

## Current Architecture

```
Keyboard
    │
stdin
    │
Command Engine
    │
Function Pointer Lookup
    │
Command Handler
    │
Console Output
```

---

## Current Status

✅ Phase 1 Completed

- Character input from console
- Command recognition
- Command execution
- Modular architecture
- Function pointer dispatch

---

## Future Work

- Replace stdin with UART.
- Add packet parser.
- Process binary telecommands.
- Integrate with FreeRTOS.
- Integrate with the OBDH firmware.
