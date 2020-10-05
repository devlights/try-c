cmake_minimum_required(VERSION 3.10)
project(sizeof_int
        DESCRIPTION "sizeof(int) のサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} sizeof_int.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
