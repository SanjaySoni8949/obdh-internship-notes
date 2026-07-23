# obdh-internship-notes





Shell Prototype

This project implements a modular command-line shell in C as part of the OBDH internship. The shell features character-by-character input processing, tokenization (argc/argv), dynamic command registration, and a command dispatch engine. The current implementation runs on a desktop using stdin for prototyping and is designed to be portable to embedded platforms (MSP430/UART) by replacing the input/output layer.

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
tokenizer.c
tokenizer.h
```





## Future Work

- Replace stdin with UART.
- Add packet parser.
- Process binary telecommands.
- Integrate with FreeRTOS.
- Integrate with the OBDH firmware.
