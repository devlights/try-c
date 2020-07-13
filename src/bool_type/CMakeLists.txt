cmake_minimum_required(VERSION 3.10)
project(bool_type
        DESCRIPTION "bool 型のサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} bool_type.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)