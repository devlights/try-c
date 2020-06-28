cmake_minimum_required(VERSION 3.16)
project(forloop
        DESCRIPTION "for-loop example"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} forloop.c)