CC       := gcc
CFLAGS   := -Wall -Wextra -std=c99 -O0 -g3
CPPFLAGS := -I.
LDFLAGS  := -L.
LDLIBS   := 

PROGRAM  := app
SRCS     := $(shell find $(CURDIR) -name '*.c' -type f)
OBJS     := $(SRCS:%.c=%.o)

all: run

build: $(PROGRAM)

run: build
	./$(PROGRAM)

clean:
	$(RM) $(OBJS) $(PROGRAM)

$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(PROGRAM)

.PHONY: all clean build run