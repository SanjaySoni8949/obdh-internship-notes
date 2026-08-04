# Changelog

All notable changes to this project are documented in this file.

The project follows Semantic Versioning (`MAJOR.MINOR.PATCH`).

---

# [1.0.0] - Initial Release

## Added

### Core Library
- Reusable command shell library
- Modular shell architecture
- Command buffer
- Character-by-character input processing
- Tokenizer (`argc` / `argv`)
- Dynamic command registration
- Function pointer-based command dispatch
- Generic platform I/O abstraction (`shell_io`)

### Built-in Commands
- `help`
- `help <command>`
- `ping`
- `echo`
- `status`
- `version`
- `exit`
- Command aliases (`quit`, `?`)

### Features
- Command metadata (description and usage)
- Unknown command handling
- Multiple-space handling
- Backspace handling
- TAB normalization
- Maximum command length protection

### Build System
- CMake support
- Install rules for the command shell library
- Linux desktop demonstration

### Documentation
- Project README
- API documentation
- Architecture overview
- Results documentation
- Demo GIF
- MIT License
- `.gitignore`

---

# Future Roadmap

Future releases may include:

- Event-driven character processing
- UART backend
- FreeRTOS integration
- Embedded platform support
- Command history
- Auto-completion
- Quoted string support
- Escape sequence support
- Configurable command registry
- Unit tests
