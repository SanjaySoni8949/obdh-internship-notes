# Portable Layer

The `portable` folder contains processor- and compiler-specific source files.

A project only includes the files for its target processor and compiler.

Example:

- Compiler: GCC
- Processor: MSP430

Path:

FreeRTOS/Source/portable/GCC/MSP430

## Memory Management

The `MemMang` folder contains different heap implementations (`heap_1.c` to `heap_5.c`).

If dynamic memory allocation is enabled, the project includes one heap implementation or provides its own.
