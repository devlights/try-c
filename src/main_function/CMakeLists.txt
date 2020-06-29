cmake_minimum_required(VERSION 3.16)
project(main_function
        DESCRIPTION "メイン関数のサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} main_func.c)
