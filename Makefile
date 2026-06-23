CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = todo
OBJS = main.o ui.o logic.o storage.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c logic.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	.\$(TARGET).exe

clean:
	del /Q $(OBJS) $(TARGET).exe 2>nul

zip:
	zip -r submit.zip *.c *.h Makefile data/

.PHONY: run clean zip