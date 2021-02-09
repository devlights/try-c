APP := $(shell basename $(PWD))
SRC := $(shell find . -name "*.c" -type f)

run:
	@gcc -o $(APP) -std=c11 -Wall -Wextra $(SRC)
	@./$(APP)
	@rm -f ./$(APP)