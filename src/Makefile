CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET = ../build/Quest_1
SOURCES = dmanager_module.c
STAGE = door_struct

all: $(STAGE)

$(STAGE): $(SOURCES)
	mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -rf build

rebuild: clean all

.PHONY: all clean rebuild