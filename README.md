# Generic Command Shell

A modular, reusable command-line shell library written in C.

The project was developed as a desktop prototype for future deployment on embedded systems such as MSP430 and FreeRTOS-based platforms. It demonstrates clean software architecture through platform abstraction, modular design, and dynamic command registration.

The project was refactored from a desktop prototype into a reusable C library by separating the core shell logic from platform-specific implementations through a generic I/O abstraction layer (shell_io).
---

# Features

- Reusable command shell library
- Modular architecture
- Dynamic command registration
- Function pointer based command dispatch
- Tokenizer using `argc` / `argv`
- Platform abstraction layer (`shell_io`)
- Command metadata (description & usage)
- Command aliases
- Linux desktop demonstration
- Easy porting to embedded platforms

---

# Architecture

```
                    Application
                          │
                          ▼
                 Command Shell Library
                          │
        ┌─────────────────┴─────────────────┐
        ▼                                   ▼
     Tokenizer                      Command Engine
                          │
                          ▼
                  Registered Commands
                          │
                          ▼
                    Command Callback
                          │
                          ▼
                  Platform I/O Layer
                          │
            ┌─────────────┴─────────────┐
            ▼                           ▼
      Linux Console              FreeRTOS (Future)
```

---

# Project Structure

```
.
├── core
│   ├── include
│   └── src
│
├── platform
│   ├── Linux
│   └── FreeRTOS
│
├── examples
│   └── desktop_demo
│
├── RESULTS
│   ├── demo.gif
│   ├── echo.png
│   ├── multi_spaces.png
│   └── README.md
│
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

# Building

## Requirements

- CMake 3.15+
- GCC / MinGW

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

```bash
./desktop_demo
```

Windows

```bash
desktop_demo.exe
```

---

# Example Session

```text
> ping
PONG

> help

Available Commands

ping
help
status
echo
version
exit
```

```text
> echo Hello World

Hello World
```

```text
> help ping

Command     : ping
Description : Check shell connectivity
Usage       : ping
```

---

# Results

The `RESULTS` directory contains:

- Demo GIF
- Echo command demonstration
- Multiple-space handling demonstration

---

# Current Library Components

## Core

- Shell
- Command Engine
- Tokenizer

## Platform Layer

- Linux Console
- FreeRTOS placeholder

## Example

- Desktop demonstration application

---

# Future Improvements

Planned improvements include:

- Event-driven character processing
- UART backend
- FreeRTOS task integration
- Command history
- Auto-completion
- Quoted string support
- Embedded hardware support

---

# License

This project is licensed under the MIT License.

See the LICENSE file for details.

---

# Acknowledgements

This project was developed during the SpaceLab UFSC internship as part of the OBDH command shell prototype.

---

# Author

**Sanjay Soni**

Electronics and Communication Engineering (ECE)

Designed as a reusable command shell library for future embedded applications.
