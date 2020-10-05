cmake_minimum_required(VERSION 3.10)
project(return_exit_success
        DESCRIPTION "stdlib.h の EXIT_SUCCESS を利用するサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} return_exit_success.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)