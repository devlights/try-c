cmake_minimum_required(VERSION 3.10)
project(${so_lib_name}
        LANGUAGES C)

add_library(${PROJECT_NAME} SHARED lib.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)