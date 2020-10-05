cmake_minimum_required(VERSION 3.10)
project(static_lib
        DESCRIPTION "静的ライブラリのサンプル"
        LANGUAGES C)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} static_lib.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_link_libraries(${PROJECT_NAME} _staticlib)