cmake_minimum_required(VERSION 3.10)
project(sample_shared_lib
        DESCRIPTION "サンプル共有ライブラリ"
        LANGUAGES C)

# ライブラリの出力場所を変更
#
# 以下の２つを指定する必要がある
#   - https://faithandbrave.hateblo.jp/entry/2014/05/14/162719
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED sample_shared_lib.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

