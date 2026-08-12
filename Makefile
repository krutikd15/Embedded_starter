CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c \
      src/logger.c \
      src/sensor.c \
      src/system_monitor.c

TARGET = device_monitor.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del $(TARGET)