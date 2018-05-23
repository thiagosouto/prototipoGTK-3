LIBS = `pkg-config --cflags --libs gtk+-3.0`
CC = g++
BIN = $(wildcard *.gtk)
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: $(OBJS) 

%: %.c 
	$(CC) -o $@.gtk $< $(LIBS)

clean:
	rm -rf $(BIN) 
	clear

