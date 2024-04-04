DESTDIR = .
PROGRAM = app
SRCS    = $(shell find $(PWD) -name "*.c" -type f)
OBJS    = $(SRCS:%.c=%.o)
CC      = clang
INCDIRS = 
CFLAGS  = -g -O0 -Wall -Wextra -std=c17
LDFLAGS =
LDLIBS  =

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(DESTDIR)/$(PROGRAM) $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCDIRS)

.PHONY: build
build: $(PROGRAM)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DESTDIR)/$(PROGRAM)

.PHONY: run
run: build
	@$(DESTDIR)/$(PROGRAM)
