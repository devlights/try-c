cmake_minimum_required(VERSION 3.10)
project(constants_octal
        DESCRIPTION "8進数定数のサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} constants_octal.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
