# How a Task is Created in FreeRTOS

A FreeRTOS task is created in three steps:

## 1. Define the Task Function

First, a function is written that contains the task's behavior.

```c
void vTaskHeartbeat(void *p)
{
    while(1)
    {
        // Task code
    }
}
```

This only defines what the task will do. The task is not running yet.

---

## 2. Declare a Task Handle

A task handle is created to store a reference to the task.

```c
xTaskHandle xTaskHeartbeatHandle;
```

The handle can later be used to suspend, resume, delete, or monitor the task.

---

## 3. Create the Task

The task is created using `xTaskCreate()`.

```c
xTaskCreate(
    vTaskHeartbeat,
    TASK_HEARTBEAT_NAME,
    TASK_HEARTBEAT_STACK_SIZE,
    NULL,
    TASK_HEARTBEAT_PRIORITY,
    &xTaskHeartbeatHandle
);
```

Parameters:

* `vTaskHeartbeat` → Task function.
* `TASK_HEARTBEAT_NAME` → Task name.
* `TASK_HEARTBEAT_STACK_SIZE` → Memory allocated to the task.
* `NULL` → Parameter passed to the task.
* `TASK_HEARTBEAT_PRIORITY` → Task priority.
* `&xTaskHeartbeatHandle` → Stores the created task handle.

---

## Execution Flow

```text
Task Function Defined
          ↓
Task Handle Declared
          ↓
xTaskCreate() Called
          ↓
Task Added to Scheduler
          ↓
Task Starts Running
```

## Example from OBDH

The Heartbeat Task is defined in `heartbeat.c` and created in `tasks.c` using `xTaskCreate()`. Once created, the FreeRTOS scheduler executes it according to its priority and timing requirements.
