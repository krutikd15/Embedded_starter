#include <stdio.h>
#include "logger.h"
#include "sensor.h"
#include "system_monitor.h"
#include "uart.h"

int main(void){
    if (logger_init() != 0) {
        printf("Failed to initialize logger\n");
        return 1;
    }
    log_info("System Starting");

    if (uart_init(115200) != 0)
    {
        log_error("UART initialization failed");
        logger_close();
        return 1;
    }
    uart_send_string("Embedded Device Monitor Started\n");

    if (sensor_init() != 0) {
        log_error("Failed to initialize sensor");
        logger_close();
        return 1;
    }
    log_info("Sensor Initialized Successfully");

    for (int i=0; i<10; i++){
        system_monitor_run();
    }
    
    uart_send_string("Embedded Device Monitor Stopped\n");
    log_info("System Shutting Down");
    uart_close();
    logger_close();

    return 0;

}