
all: clean run

clean:
	rm -rf cmake-build-debug/

build:
	mkdir -p cmake-build-debug && \
	cd cmake-build-debug && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && \
	make

run: build
	cd cmake-build-debug && \
	./try-c

.PHONY: all build run clean
