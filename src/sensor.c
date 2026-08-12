#include <stdlib.h>
#include <time.h>

#include "sensor.h"

int sensor_init(void)
{
    srand((unsigned int)time(NULL));

    return 0;
}

int sensor_read_temperature(float *temperature)
{
    int random_value;

    if (temperature == NULL)
    {
        return -1;
    }

    random_value = rand() % 100;

    /*
        Simulate a sensor failure.

        Around 10% of the time,
        the sensor will fail.
    */
    if (random_value < 10)
    {
        return -1;
    }

    /*
        Generate temperature between
        roughly 20.0 C and 44.9 C
    */
    *temperature = 20.0f + (rand() % 250) / 10.0f;

    return 0;
}