cmake_minimum_required(VERSION 3.10)
project(helloworld
        DESCRIPTION "HelloWorld program"
        LANGUAGES C)

add_executable(${PROJECT_NAME} helloworld.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
