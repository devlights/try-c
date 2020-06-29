cmake_minimum_required(VERSION 3.16)
project(extern_function
        DESCRIPTION "他のファイルで定義されている関数を呼び出すサンプル"
        LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(${PROJECT_NAME}
        main.c
        sub.c)