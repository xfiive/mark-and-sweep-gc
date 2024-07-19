CC = gcc
CFLAGS = -std=c11 -Wall -Werror -g
LDLIBS = -lm

TARGET = main

SRCS = main.c \
       object/object.c \
       stack/stack.c \
       vm/vm.c

HDRS = object/object.h \
       stack/stack.h \
       vm/vm.h

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
