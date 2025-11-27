CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET1 = ../build/Quest_1.exe
TARGET2 = ../build/Quest_2.exe
SOURCES1 = dmanager_module.c
SOURCES2 = list_test.c list.c
STAGE1 = door_struct
STAGE2 = list_test

all: $(STAGE1) $(STAGE2)

$(STAGE1): $(SOURCES1) door_struct.h
	-mkdir ../build 2>nul
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCES1)

$(STAGE2): $(SOURCES2) list.h door_struct.h
	-mkdir ../build 2>nul
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCES2)

clean:
	-rmdir /s /q ..\build 2>nul

rebuild: clean all

.PHONY: all clean rebuild $(STAGE1) $(STAGE2)