LIBS = `pkg-config --cflags --libs gtk+-3.0`
CC = g++
BIN = bin
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: mkdirs $(OBJS)

mkdirs:
	mkdir -p $(BIN)

%: %.c mkdirs
	$(CC) -o $@  $< $(LIBS)

clean:
	rm -rf $(BIN)
	clear

.PHONY: clean mkdirs
