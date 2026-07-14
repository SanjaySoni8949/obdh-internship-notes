# FreeRTOS Header Files

Any source file that uses the FreeRTOS API should first include:

```c
#include "FreeRTOS.h"
```

Then include the required header file based on the feature being used.

| Header File        | Purpose                  |
| ------------------ | ------------------------ |
| `task.h`           | Task management APIs     |
| `queue.h`          | Queue APIs               |
| `semphr.h`         | Semaphore and Mutex APIs |
| `timers.h`         | Software Timer APIs      |
| `event_groups.h`   | Event Group APIs         |
| `stream_buffer.h`  | Stream Buffer APIs       |
| `message_buffer.h` | Message Buffer APIs      |
| `croutine.h`       | Co-routine APIs          |

> **Note:** Do **not** include `FreeRTOSConfig.h` directly. Always include `FreeRTOS.h`, which automatically includes it.
