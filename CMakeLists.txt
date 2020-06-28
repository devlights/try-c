cmake_minimum_required(VERSION 3.16)
project(try-c)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_subdirectory(src/helloworld)
add_subdirectory(src/forloop)