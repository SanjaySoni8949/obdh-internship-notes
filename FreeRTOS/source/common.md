FreeRTOS Source Files Common to All Ports

tasks.c and list.c implement the core FreeRTOS kernel functionality and are always required.
They are located directly in the FreeRTOS/Source directory.
The same directory also contains the following optional source files:
queue.c
queue.c provides both queue and semaphore services, as described later in this book. queue.c is nearly always required.

timers.c
timers.c provides software timer functionality. It only needs to be built if the application uses software timers.

event_groups.c
event_groups.c provides event group functionality. It only needs to be built if the application uses event groups.

stream_buffer.c
stream_buffer.c provides both stream buffer and message buffer functionality. It only needs to be built if the application uses stream or message buffers.

croutine.c
croutine.c implements the FreeRTOS co-routine functionality. It only needs to be built if the application
uses co-routines. Co-routines are intended for use on very small microcontrollers, are rarely used now.
They are, therefore, no longer maintained, and their use is not recommended for new designs. Co
routines are not described in this book.
