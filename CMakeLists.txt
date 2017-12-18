# ---------------------------------------------
# CMake の設定
# ---------------------------------------------
cmake_minimum_required(VERSION 3.9)
project(try-c)

set(CMAKE_C_STANDARD 11)

# ---------------------------------------------
# 対象ファイルリストを構築
# ---------------------------------------------
file(GLOB HEADER_FILES include/*.h)
file(GLOB SOURCE_FILES src/*.c)

# ---------------------------------------------
# インクルードファイルがあるディレクトリを設定
# ---------------------------------------------
include_directories(include)

# ---------------------------------------------
# デバッグ用ダンプ
# ---------------------------------------------
# message(STATUS "*** dump start cmake variables ***")
# get_cmake_property(_variableNames VARIABLES)
# foreach(_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
# message(STATUS "*** dump end ***")

# ---------------------------------------------
# コンパイル設定
# ---------------------------------------------
add_executable(tryc ${SOURCE_FILES} ${HEADER_FILES})