cmake_minimum_required(VERSION 3.16)
project(sample_shared_lib
        DESCRIPTION "サンプル共有ライブラリ"
        LANGUAGES C)

message(STATUS ${CMAKE_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED sample_shared_lib.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

