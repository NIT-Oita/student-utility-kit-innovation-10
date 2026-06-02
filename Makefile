CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = taskman
OBJS = main.o ui.o logic.o storage.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
%.o: %.c logic.h
	$(CC) $(CFLAGS) -c $< -o $@
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe
zip:
	zip -r submit.zip *.c *.h Makefile data/
.PHONY: run clean zip