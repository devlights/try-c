cmake_minimum_required(VERSION 3.10)
project(cello_helloworld
        DESCRIPTION "Cello helloworld"
        LANGUAGES C)

# LD_LIBRARY_PATH を見るように設定
#   - https://stackoverflow.com/questions/30380257/how-can-ld-library-path-be-changed-within-cmake
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# libCello.a は、/usr/local/lib に配置される
find_library(cello_lib
             NAMES Cello 
             REQUIRED)
             
# Cello を 利用する際に pthread が必要となるため設定
find_library(pthread_lib
             NAMES pthread
             REQUIRED)

add_executable(${PROJECT_NAME} cello_helloworld.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
target_link_libraries(${PROJECT_NAME} ${cello_lib} ${pthread_lib})