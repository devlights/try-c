cmake_minimum_required(VERSION 3.10)
project(shared_lib
        DESCRIPTION "共有ライブラリ(so)のサンプル"
        LANGUAGES C)

# 自身のCMake管理下にある共有ライブラリ
set(so_lib_name _sharedlib)
add_subdirectory(lib)

# 自身とは別に存在する外部共有ライブラリ
#
# - 最初の引数は 見つかったライブラリの場所 が設定される変数の名前
# - 次の引数は、対象のライブラリの名前 (複数可能)
# - PATHS は、対象のライブラリが標準ライブラリパス、LD_LIBRARY_PATH 以外の場所の場合のヒントパス (複数可能)
# - REQURED は、見つからなかった場合にビルドをエラーにして中止するという意味
#
# - https://stackoverflow.com/questions/8774593/cmake-link-to-external-library
# - https://cmake.org/cmake/help/latest/command/find_library.html?highlight=find_library
find_library(external_lib
        NAMES sample_shared_lib
        PATHS "${CMAKE_SOURCE_DIR}/sample_shared_lib"
        REQUIRED)

add_executable(${PROJECT_NAME} shared_lib.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_link_libraries(${PROJECT_NAME} ${so_lib_name} ${external_lib})
