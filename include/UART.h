#ifndef UART_H
#define UART_H

#include <stddef.h>

int uart_init(unsigned int baud_rate);
int uart_send_byte(char data);
int uart_send_string(const char *message);
int uart_receive_byte(char *data);
void uart_close(void);

#endif // UART_H
