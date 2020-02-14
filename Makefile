
all: clean run

clean:
	rm -rf build/

build:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	make

run: build
	cd build && \
	./tryc

.PHONY: all build run clean
