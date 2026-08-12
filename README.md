# Embedded Device Monitoring System

A software-based Embedded C project created to learn embedded software development concepts without requiring physical hardware.

## Project Goal

The goal of this project is to progressively learn:

- Embedded C
- Modular C programming
- Sensor drivers
- Logging
- Error handling
- Failure analysis
- GPIO
- Interrupts
- UART
- I2C
- SPI
- State machines
- Watchdog timers
- GDB/JTAG debugging
- RTOS concepts

The first version uses simulated hardware. Future versions will move the same software concepts to an STM32 microcontroller.

## Version 1

Version 1 implements a simulated temperature monitoring system.

The application:

1. Initializes the logging system.
2. Initializes a simulated temperature sensor.
3. Reads temperature values.
4. Simulates occasional sensor failures.
5. Logs system behavior.
6. Detects high temperatures.
7. Generates INFO, DEBUG, WARN and ERROR logs.

## Project Structure

    embedded_device_monitor/
    |
    ├── src/
    │   ├── main.c
    │   ├── sensor.c
    │   ├── logger.c
    │   └── system_monitor.c
    |
    ├── include/
    │   ├── sensor.h
    │   ├── logger.h
    │   └── system_monitor.h
    |
    ├── logs/
    │   └── device.log
    |
    ├── Makefile
    └── README.md

## Modules

### main.c

Controls the overall application flow.

It initializes the logger and sensor, runs the monitoring system, and shuts down the application.

### sensor.c / sensor.h

Simulates a temperature sensor.

The sensor normally returns a temperature value but occasionally generates a simulated failure.

### logger.c / logger.h

Provides the logging system.

Supported log levels:

- DEBUG
- INFO
- WARN
- ERROR

Logs are written to:

    logs/device.log

### system_monitor.c / system_monitor.h

Contains the main monitoring logic.

It reads the temperature sensor, detects sensor failures, logs temperature values, and generates warnings when the temperature is too high.

## Build

Using GCC:

    gcc src/main.c src/logger.c src/sensor.c src/system_monitor.c -Iinclude -o device_monitor.exe

Or using Make:

    make

## Run

On Windows PowerShell:

    .\device_monitor.exe

## Example Log

    21:30:01 INFO  System starting
    21:30:01 INFO  Sensor initialized successfully
    21:30:01 DEBUG Reading temperature sensor
    21:30:01 INFO  Temperature = 27.5 C
    21:30:01 DEBUG Reading temperature sensor
    21:30:01 INFO  Temperature = 42.3 C
    21:30:01 WARN  High temperature detected
    21:30:01 DEBUG Reading temperature sensor
    21:30:01 ERROR Temperature sensor read failed
    21:30:01 INFO  System shutting down

## Future Development

Future versions will add:

- Sensor retry and recovery
- GPIO simulation
- Interrupt handling
- UART communication
- I2C and SPI drivers
- State machines
- Watchdog timer
- GDB debugging
- FreeRTOS
- STM32 hardware support
