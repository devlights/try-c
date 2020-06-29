cmake_minimum_required(VERSION 3.16)
project(escape_sequence
        DESCRIPTION "エスケープシーケンスのサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME} escape_sequence.c)