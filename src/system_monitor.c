#include <stdio.h>

#include "sensor.h"
#include "logger.h"
#include "system_monitor.h"

void system_monitor_run(void)
{
    float temperature;
    char message[100];

    log_debug("Reading temperature sensor");

    if (sensor_read_temperature(&temperature) != 0)
    {
        log_error("Temperature sensor read failed");
        return;
    }

    snprintf(
        message,
        sizeof(message),
        "Temperature = %.1f C",
        temperature
    );

    log_info(message);

    if (temperature > 40.0f)
    {
        log_warning("High temperature detected");
    }
}