cmake_minimum_required(VERSION 3.16)
project(header_include
        DESCRIPTION "ヘッダーファイルのインクルードについてのサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(header_include header_include.c)
target_include_directories(${PROJECT_NAME} PRIVATE include)
