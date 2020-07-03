cmake_minimum_required(VERSION 3.16)
project(return_exit_success
        DESCRIPTION "stdlib.h の EXIT_SUCCESS を利用するサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} return_exit_success.c)