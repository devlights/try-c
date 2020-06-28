cmake_minimum_required(VERSION 3.16)
project(helloworld
        DESCRIPTION "HelloWorld program"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} helloworld.c)
