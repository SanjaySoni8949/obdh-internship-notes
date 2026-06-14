# Event Groups in FreeRTOS

## What is an Event Group?

An Event Group is a synchronization mechanism used in FreeRTOS.

It allows tasks to communicate using bits (flags).

A task can wait for a specific event to occur before continuing execution.

---

## Why are Event Groups used?

Event Groups are used when one task needs to know that another task has completed some action.

Example:

Startup Task
↓
Initializes hardware
↓
Sets "Startup Done" bit
↓
Heartbeat Task wakes up and starts running

---

## Example from OBDH

In the Heartbeat Task:

```c
(void)xEventGroupWaitBits(
    task_startup_status,
    TASK_STARTUP_DONE,
    pdFALSE,
    pdTRUE,
    pdMS_TO_TICKS(TASK_HEARTBEAT_INIT_TIMEOUT_MS)
);
```

Purpose:

The Heartbeat Task waits until the Startup Task finishes initialization.

---

## Event Bit Example

```c
#define TASK_STARTUP_DONE (1U << 0)
```

Meaning:

Bit 0 represents that the Startup Task has completed successfully.

---

## Event Group Creation

```c
task_startup_status = xEventGroupCreate();
```

Creates an Event Group used by the system tasks.

---

## Analogy

Think of an Event Group as a notice board.

Startup Task writes:

"Initialization Complete"

Heartbeat Task checks the notice board and starts working only after seeing that message.

---

## Key Idea

Event Groups are used for synchronization between tasks.

They help tasks wait for important events instead of constantly checking conditions in a loop.
