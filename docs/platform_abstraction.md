# Platform Abstraction

## Overview

The Generic Serial Command Shell is designed to be platform-independent. Instead of directly using operating system or hardware-specific functions, all input and output operations are performed through a platform abstraction layer.

This design allows the shell to run on different platforms by changing only the platform-specific implementation while keeping the core shell logic unchanged.

---

# Why Platform Abstraction?

If the shell directly used standard C library functions such as:

```c
getchar();
putchar();
printf();
```

it would only work on systems that provide a standard console.

Most embedded systems do not have a keyboard or terminal. Instead, communication typically occurs through interfaces such as:

- UART
- USB Serial
- Bluetooth Serial
- Virtual COM Port

By introducing a platform abstraction layer, the shell can support different communication interfaces without modifying its core modules.

---

# Architecture

Without platform abstraction:

```
Keyboard
    │
    ▼
 getchar()
    │
    ▼
 Shell
```

With platform abstraction:

```
Keyboard / UART / USB / Bluetooth
                │
                ▼
      Platform Abstraction Layer
                │
                ▼
             Shell
```

The shell communicates only with the platform layer and has no knowledge of the underlying hardware.

---

# Platform Interface

The current platform interface consists of three functions.

```c
char shell_getchar(void);

void shell_putchar(char ch);

void shell_print(const char *str);
```

These functions provide all input and output services required by the shell.

---

# shell_getchar()

Reads one character from the input device.

Desktop implementation:

```c
char shell_getchar(void)
{
    return getchar();
}
```

Future embedded implementation:

```c
char shell_getchar(void)
{
    return uart_receive();
}
```

The shell does not need to know where the character comes from.

---

# shell_putchar()

Outputs a single character.

Desktop:

```c
putchar(ch);
```

Embedded:

```c
uart_transmit(ch);
```

---

# shell_print()

Outputs a string.

Desktop:

```c
printf("%s", str);
```

Embedded:

```c
uart_write(str);
```

Again, the shell simply calls `shell_print()` without knowing how the data is transmitted.

---

# Benefits

## Portability

The shell can be moved to a different platform by changing only the platform layer.

---

## Hardware Independence

The shell contains no hardware-specific code.

This makes the project reusable across multiple embedded platforms.

---

## Maintainability

Hardware-related changes remain isolated in one module.

The tokenizer, command engine, and command implementations require no modifications.

---

## Testability

The desktop implementation allows rapid testing and debugging without requiring embedded hardware.

Once the shell behaves correctly on the desktop, the same logic can be reused on the target system.

---

# Current Implementation

The current prototype uses the standard input and output provided by the C library.

```
Keyboard
    │
getchar()

↓

Shell

↓

printf()

↓

Console
```

This allows the shell to be developed and tested on a desktop computer.

---

# Future Embedded Implementation

When ported to an embedded system, only the platform layer changes.

```
UART RX
   │
   ▼
shell_getchar()

↓

Shell

↓

shell_print()

↓

UART TX
```

The shell itself remains unchanged.

---

# Design Principle

The platform abstraction layer follows the principle of **separation of concerns**.

The shell focuses only on processing commands.

The platform layer handles all hardware-specific operations.

This separation makes the system easier to understand, maintain, and extend.

---

# Future Enhancements

The platform layer can be extended to support:

- USB CDC
- Bluetooth Serial
- CAN Bus
- TCP/IP sockets
- RTOS message queues
- Logging interfaces

Because the shell interacts only with the platform interface, these enhancements require little or no modification to the shell itself.

---

# Summary

The platform abstraction layer isolates all hardware-dependent input and output operations from the rest of the shell.

By communicating only through a small set of platform functions, the Generic Serial Command Shell remains portable, reusable, and easy to adapt to desktop applications as well as embedded systems.
