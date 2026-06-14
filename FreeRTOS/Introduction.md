# FreeRTOS

## What is FreeRTOS?

FreeRTOS is a Real-Time Operating System (RTOS) designed for embedded systems and microcontrollers.

It allows multiple tasks to run concurrently and provides mechanisms for scheduling, communication, and synchronization between tasks.


EXAMPLE:-Without FreeRTOS

Imagine you're alone in a hostel room and have to do:

1. Study
2. Wash clothes
3. Cook food
4. Answer phone calls

You do them one by one:

Study for 1 hour
↓
Wash clothes
↓
Cook food
↓
Answer phone

If a phone call comes while you're cooking, it has to wait.

This is similar to:

```c while(1)
{
    study();
    wash_clothes();
    cook_food();
    answer_phone();
}
```

With FreeRTOS

Now imagine you're a hostel manager.

You have workers:

Worker 1 = Study Task
Worker 2 = Laundry Task
Worker 3 = Cooking Task
Worker 4 = Phone Task

You assign work to each.

Study Task      → running
Cooking Task    → running
Phone Task      → waiting for call
Laundry Task    → waiting

FreeRTOS acts like the manager.

This manager is called the:

Scheduler
Scheduling

The scheduler decides:

Who gets CPU time?
For how long?
Who should run next?
---

## Why is it used?

Without FreeRTOS:

```c
while(1)
{
    task1();
    task2();
    task3();
}
```

Everything must be managed manually.

With FreeRTOS:

- Task management
- Scheduling
- Delays
- Queues
- Semaphores
- Event Groups

are provided by the operating system.

---

## Concepts Learned

### Task

A task is an independent unit of execution.

Example:

```c
void vTaskHeartbeat(void *p)
{
    while(1)
    {
        ...
    }
}
```

---

### Task Handle

```c
xTaskHandle xTaskHeartbeatHandle;
```

Stores a reference to a task.

Used to suspend, resume, or delete tasks.

---

### Event Group

Used for synchronization between tasks.

Example:

```c
xEventGroupWaitBits(...)
```

Heartbeat waits for Startup to finish.

---

### Heartbeat Task

Purpose:

- Indicates firmware is alive.
- Toggles the system LED every 500 ms.

Files:

- heartbeat.c
- heartbeat.h

---

## Questions to Explore

- How are tasks created?
- How does the scheduler work?
- How do queues work?
- How do semaphores work?
- How are telecommands processed?
