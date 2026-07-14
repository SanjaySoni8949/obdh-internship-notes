# FreeRTOS Include Paths

To compile a FreeRTOS project, the compiler must know where the required header files are located.

The following include paths are required:

1. `FreeRTOS/Source/include`

   * Contains the common FreeRTOS header files.

2. `FreeRTOS/Source/portable/[compiler]/[architecture]`

   * Contains the port-specific header files for the selected compiler and processor.

3. Path to `FreeRTOSConfig.h`

   * Contains the project-specific FreeRTOS configuration file.

> **Example:** If using GCC with an MSP430, the port path would be:
>
> `FreeRTOS/Source/portable/GCC/MSP430`
