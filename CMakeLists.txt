cmake_minimum_required(VERSION 3.6)
project(try-c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main.c)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})
file(GLOB SRC_FILES src/*.c)
add_executable(tryc ${SRC_FILES})