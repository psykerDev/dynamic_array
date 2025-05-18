# Makefile for dynamic-array-c project

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
TARGET = dynamic_array
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
