cmake_minimum_required(VERSION 3.10)
project(escape_sequence
        DESCRIPTION "エスケープシーケンスのサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} escape_sequence.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)