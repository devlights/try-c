cmake_minimum_required(VERSION 3.16)
project(bool_type
        DESCRIPTION "bool 型のサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} bool_type.c)