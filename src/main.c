#include <stdio.h>
#include "logger.h"
#include "sensor.h"
#include "system_monitor.h"

int main(void){
    if (logger_init() != 0) {
        printf("Failed to initialize logger\n");
        return 1;
    }
    log_info("System Starting");

    if (sensor_init() != 0) {
        log_error("Failed to initialize sensor");
        logger_close();
        return 1;
    }
    log_info("Sensor Initialized Successfully");

    for (int i=0; i<10; i++){
        system_monitor_run();
    }

    log_info("System Shutting Down");
    logger_close();

    return 0;

}