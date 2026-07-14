# Semaphore in FreeRTOS

## What is a Semaphore?

A semaphore is used to synchronize tasks.

It helps tasks share resources safely.

It does not transfer data.

It only gives permission or signals an event.

## Types

* **Binary Semaphore** – Used for task synchronization.
* **Counting Semaphore** – Used when multiple resources are available.
* **Mutex** – Protects shared resources like UART, SPI, and I²C.

## FreeRTOS APIs

```c
SemaphoreHandle_t xSemaphore;

xSemaphore = xSemaphoreCreateBinary();

xSemaphoreTake(xSemaphore, portMAX_DELAY);

xSemaphoreGive(xSemaphore);
```

## Example

Two tasks want to use UART.

Task A takes the semaphore.

Task B waits.

After Task A finishes, it gives the semaphore.

Then Task B can use UART.

## Conclusion

Semaphores prevent resource conflicts.

They help tasks work together safely.

They are an important feature of FreeRTOS.
