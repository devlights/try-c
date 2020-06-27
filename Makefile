CMAKE_DIR := cmake-build-debug

all: clean run

clean:
	rm -rf $(CMAKE_DIR)/

build:
	mkdir -p $(CMAKE_DIR) && \
	cd $(CMAKE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && \
	make

run: build
	cd $(CMAKE_DIR) && \
	./try-c

.PHONY: all build run clean
