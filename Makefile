example := dummy
CMAKE_DIR := cmake-build-debug

all: clean build

clean:
	rm -rf $(CMAKE_DIR)/

build:
	mkdir -p $(CMAKE_DIR) && \
	cd $(CMAKE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && \
	cmake --build .

list: build
	cd $(CMAKE_DIR)/src && \
	echo '***** Available examples *****' && \
	ls | sed -e 's/\s+/\r/g' | sort

run: build
	cd $(CMAKE_DIR)/src/${example} && \
	echo "***** START [${example}] *****" && \
	./${example}

.PHONY: all clean build list run
