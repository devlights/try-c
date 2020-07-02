cmake_minimum_required(VERSION 3.16)
project(sizeof_int
        DESCRIPTION "sizeof(int) のサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} sizeof_int.c)
