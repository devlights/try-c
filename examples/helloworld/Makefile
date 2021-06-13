APP := $(shell basename $(PWD))
SRC := $(shell find $(PWD) -name "*.c" -type f)

run:
	@gcc -o $(APP) -std=c11 -Wall -Wextra $(SRC)
	@$(PWD)/$(APP)
	@rm -f $(PWD)/$(APP)