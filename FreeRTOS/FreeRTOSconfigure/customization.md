Customization

FreeRTOS is customized using a configuration file called FreeRTOSConfig.h.

Every FreeRTOS application must have a FreeRTOSConfig.h header file in its pre-processor include path. 

FreeRTOSConfig.h tailors the RTOS kernel to the application being built. It is therefore specific to the application, not the RTOS,
and should be located in an application directory, not in one of the RTOS kernel source code directories.

Each demo application included in the RTOS source code download has its own FreeRTOSConfig.h file. 

Some of the demos are quite old and do not contain all the available configuration options. 

Configuration options that are omitted are set to a default value within an RTOS source file.


For more about customization of FreeRTOS configuration visit : - https://www.freertos.org/a00110.html
