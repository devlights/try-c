target := helloworld
CMAKE_DIR := cmake-build-debug

.PHONY: all
all: clean build

.PHONY: clean
clean: clean_samplelib
	@rm -rf $(CMAKE_DIR)/

.PHONY: build
build: build_samplelib
	@mkdir -p $(CMAKE_DIR) && \
	cd $(CMAKE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. && \
	cmake --build .

.PHONY: build-target
build-target:
	@cmake --build $(CMAKE_DIR) --target ${target} --clean-first

.PHONY: list
list: build
	@cd $(CMAKE_DIR)/src && \
	echo '***** Available examples *****' && \
	ls | sed -e 's/\s+/\r/g' | sort

.PHONY: run
run: build-target
	@cd $(CMAKE_DIR)/src/${target} && \
	echo "***** START [${target}] *****" && \
	./${target} && \
	echo "*****  END  [${target}] *****"

.PHONY: clean_samplelib
clean_samplelib:
	@cd sample_shared_lib/ && \
	if [ -d "build" ];then cmake --build build --target clean; else true; fi && \
	rm -rf build

.PHONY: build_samplelib
build_samplelib:
	@cd sample_shared_lib/ && \
	mkdir -p build && \
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build && \
	cmake --build build
