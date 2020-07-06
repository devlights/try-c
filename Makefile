example := dummy
CMAKE_DIR := cmake-build-debug

.PHONY: all
all: clean build

.PHONY: clean
clean: clean_samplelib
	rm -rf $(CMAKE_DIR)/

.PHONY: build
build: build_samplelib
	mkdir -p $(CMAKE_DIR) && \
	cd $(CMAKE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && \
	cmake --build .

.PHONY: list
list: build
	cd $(CMAKE_DIR)/src && \
	echo '***** Available examples *****' && \
	ls | sed -e 's/\s+/\r/g' | sort

.PHONY: run
run: build
	cd $(CMAKE_DIR)/src/${example} && \
	echo "***** START [${example}] *****" && \
	./${example}

.PHONY: clean_samplelib
clean_samplelib:
	cd sample_shared_lib/ && \
	cmake --build build --target clean && \
	rm -rf build

.PHONY: build_samplelib
build_samplelib:
	cd sample_shared_lib/ && \
	mkdir build && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build && \
	cmake --build build
