CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET1 = ../build/Quest_1
TARGET2 = ../build/Quest_2
TARGET3 = ../build/Quest_3
SOURCES1 = dmanager_module.c
SOURCES2 = list_test.c list.c
SOURCES3 = stack_test.c stack.c
STAGE1 = door_struct
STAGE2 = list_test
STAGE3 = stack_test

all: $(STAGE1) $(STAGE2) $(STAGE3)

$(STAGE1): $(SOURCES1) door_struct.h
	mkdir -p ../build
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCES1)

$(STAGE2): $(SOURCES2) list.h door_struct.h
	mkdir -p ../build
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCES2)

$(STAGE3): $(SOURCES3) stack.h
	mkdir -p ../build
	$(CC) $(CFLAGS) -o $(TARGET3) $(SOURCES3)

clean:
	rm -rf ../build

rebuild: clean all

.PHONY: all clean rebuild $(STAGE1) $(STAGE2) $(STAGE3)
