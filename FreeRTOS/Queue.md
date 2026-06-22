# FreeRTOS Queue

A Queue is a FIFO (First In First Out) communication mechanism used by FreeRTOS.

Purpose:
- Communication between tasks
- Communication between ISR and tasks
- Safe transfer of data

Main APIs:

1. xQueueCreate()
   Creates a queue.

2. xQueueSend()
   Sends data to the queue.

3. xQueueReceive()
   Receives data from the queue.

4. xQueuePeek()
   Reads data without removing it.

5. uxQueueMessagesWaiting()
   Returns the number of items currently stored in the queue.
