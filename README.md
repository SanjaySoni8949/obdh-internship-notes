# Generic Serial Command Shell

A modular and portable command-line shell written in C, designed as a desktop prototype for future deployment on embedded systems.

The project demonstrates how to build a reusable command interpreter using a clean, modular architecture with dynamic command registration, argument parsing, and platform abstraction.

---

# Features

- Modular architecture
- Dynamic command registration
- Function pointer based command dispatch
- Tokenizer using `argc` / `argv`
- Platform abstraction layer
- Command metadata (description & usage)
- Command aliases
- Easy command extension
- Desktop prototype ready for embedded porting

---

# Project Goals

The primary goals of this project are:

- Learn embedded software architecture
- Build a reusable command engine
- Keep modules independent
- Simplify future porting to embedded hardware
- Demonstrate clean C programming practices

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
 Registered Commands       Unknown Command
      │
      ▼
 Command Callback
```

---

# Project Structure

```
Generic-Serial-Command-Shell/
│
├── README.md
├── CONTRIBUTING.md
│
├── docs/
│   ├── 01_Architecture.md
│   ├── 02_Command_Engine.md
│   ├── 03_Tokenizer.md
│   ├── 04_Platform_Abstraction.md
│   ├── 05_Commands.md
│   ├── 06_Developer_Guide.md
│   └── 07_Future_Work.md
│
├── command_engine.c
├── command_engine.h
├── commands.c
├── commands.h
├── tokenizer.c
├── tokenizer.h
├── shell.c
├── shell.h
├── platform_stdio.c
├── platform.h
└── main.c
```

---

# Documentation

Detailed documentation is available in the `docs/` directory.

| Document | Description |
|----------|-------------|
| Architecture | Overall system design |
| Command Engine | Command registration and execution |
| Tokenizer | Input parsing |
| Platform Abstraction | Hardware-independent design |
| Commands | User command reference |
| Developer Guide | Adding new commands |
| Future Work | Planned improvements |

---

# Example Session

```
> help

Available Commands

help
ping
echo
status
version
exit
```

```
> echo Hello Embedded World

Hello Embedded World
```

```
> help ping

Command     : ping
Description : Check shell connectivity
Usage       : ping
```

---

# Building

Compile using any standard C compiler.

Example using GCC:

```bash
gcc *.c -o shell
```

Run:

```bash
./shell
```

---

# Future Roadmap

Planned improvements include:

- UART backend
- FreeRTOS integration
- Command history
- Auto-completion
- Quoted string support
- Escape sequences
- Embedded platform support
- Unit testing

See `docs/07_Future_Work.md` for more details.

---

# Contributing

Contributions are welcome.

Please read **CONTRIBUTING.md** before submitting changes.

---

# License

This project currently has no license.

A suitable open-source license (such as the MIT License) may be added in the future.

---

# Author

Developed by **Sanjay Soni**

Electronics and Communication Engineering (ECE)

This project was developed as part of an embedded systems learning journey and is intended to serve as a reusable command shell for future embedded applications.
