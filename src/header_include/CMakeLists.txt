cmake_minimum_required(VERSION 3.16)
project(header_include
        DESCRIPTION "ヘッダーファイルのインクルードについてのサンプル"
        LANGUAGES C)

add_executable(header_include header_include.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_include_directories(${PROJECT_NAME} PRIVATE include)
