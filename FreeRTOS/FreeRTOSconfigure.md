# FreeRTOSConfig.h

`FreeRTOSConfig.h` is the configuration file of FreeRTOS.

It is used to customize the kernel according to the application's requirements.

Some common settings include:

* `configUSE_PREEMPTION` – Enables or disables preemptive scheduling.
* `configMAX_PRIORITIES` – Sets the maximum number of task priorities.
* `configTICK_RATE_HZ` – Sets the RTOS tick frequency.
* `configMINIMAL_STACK_SIZE` – Defines the minimum stack size for a task.

Each FreeRTOS project has its own `FreeRTOSConfig.h` file because different applications require different configurations.

**Note:** Include `FreeRTOS.h` in your source files instead of including `FreeRTOSConfig.h` directly.
