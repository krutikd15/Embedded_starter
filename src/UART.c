#include <stdio.h>

#include "uart.h"
#include "logger.h"

static int uart_initialized = 0;
static unsigned int current_baud_rate = 0;


int uart_init(unsigned int baud_rate)
{
    if (baud_rate == 0)
    {
        log_error("UART initialization failed: invalid baud rate");
        return -1;
    }

    current_baud_rate = baud_rate;
    uart_initialized = 1;

    log_info("UART initialized successfully");

    return 0;
}


int uart_send_byte(char data)
{
    if (uart_initialized == 0)
    {
        log_error("UART TX failed: UART not initialized");
        return -1;
    }

    /*
        Software simulation:

        In real hardware this byte would be
        written into a UART transmit register.

        Here we simply print it to the terminal.
    */

    putchar(data);
    fflush(stdout);

    return 0;
}


int uart_send_string(const char *message)
{
    if (uart_initialized == 0)
    {
        log_error("UART TX failed: UART not initialized");
        return -1;
    }

    if (message == NULL)
    {
        log_error("UART TX failed: NULL message");
        return -1;
    }

    /*
        Send one character at a time.

        This helps simulate how UART actually
        transmits individual bytes.
    */

    while (*message != '\0')
    {
        if (uart_send_byte(*message) != 0)
        {
            return -1;
        }

        message++;
    }

    return 0;
}


int uart_receive_byte(char *data)
{
    int input;

    if (uart_initialized == 0)
    {
        log_error("UART RX failed: UART not initialized");
        return -1;
    }

    if (data == NULL)
    {
        log_error("UART RX failed: invalid destination");
        return -1;
    }

    /*
        Software simulation:

        In real hardware, data would come from
        the UART receive register.

        Here we read one character from keyboard.
    */

    input = getchar();

    if (input == EOF)
    {
        log_error("UART RX failed");
        return -1;
    }

    *data = (char)input;

    return 0;
}


void uart_close(void)
{
    if (uart_initialized == 1)
    {
        log_info("UART closed");

        uart_initialized = 0;
        current_baud_rate = 0;
    }
}