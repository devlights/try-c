cmake_minimum_required(VERSION 3.16)
project(main_function
        DESCRIPTION "メイン関数のサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} main_func.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
