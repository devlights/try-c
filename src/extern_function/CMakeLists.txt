cmake_minimum_required(VERSION 3.10)
project(extern_function
        DESCRIPTION "他のファイルで定義されている関数を呼び出すサンプル"
        LANGUAGES C)

add_executable(${PROJECT_NAME} main.c sub.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)