CC = gcc
CFLAGS = -std=c11 -Wall -Werror -g
LDLIBS = -lm

TARGET = main

SRCS = $(shell find . -name '*.c')
HDRS = $(shell find . -name '*.h')

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

%: %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	./$@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
