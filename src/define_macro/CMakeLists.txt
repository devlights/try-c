cmake_minimum_required(VERSION 3.10)
project(define_macro
        DESCRIPTION "defineのサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} define_macro.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
