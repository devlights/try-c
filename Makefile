init-example:
	mkdir -p ${NAME}
	cp Makefile.template ${NAME}/Makefile
	touch ${NAME}/main.c

.PHONY: init-example