# Common FreeRTOS Source Files

The `FreeRTOS/Source` directory contains the core source files of the FreeRTOS kernel.

| File              | Description                                                                                    |
| ----------------- | ---------------------------------------------------------------------------------------------- |
| `tasks.c`         | Implements task creation, scheduling, and task management. **Required in every project.**      |
| `list.c`          | Implements linked lists used internally by the FreeRTOS kernel. **Required in every project.** |
| `queue.c`         | Provides queues, semaphores, and mutexes. Used in most FreeRTOS applications.                  |
| `timers.c`        | Provides software timer functionality. Include only if software timers are used.               |
| `event_groups.c`  | Implements Event Groups for task synchronization. Include only if needed.                      |
| `stream_buffer.c` | Provides Stream Buffers and Message Buffers for data communication.                            |
| `croutine.c`      | Implements co-routines. Rarely used and not recommended for new projects.                      |

> **Note:** Only `tasks.c` and `list.c` are required in every FreeRTOS project. Other source files are included only if the application uses their features.
