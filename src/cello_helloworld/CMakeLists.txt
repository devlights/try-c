cmake_minimum_required(VERSION 3.10)
project(cello_helloworld
        DESCRIPTION "Cello helloworld"
        LANGUAGES C)

add_executable(${PROJECT_NAME} cello_helloworld.c)

target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Linux で Cello を含めてコンパイルする際は pthread も必要
#   - http://libcello.org/learn/installation
#   - http://libcello.org/learn/cello-world
#   - http://iwiwi.hatenadiary.jp/entry/2015/02/25/012325
#   - https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
#
# この指定で以下のように link.txt が生成される
#   /usr/bin/cc -g CMakeFiles/cello_helloworld.dir/cello_helloworld.c.o -o cello_helloworld  -lCello -lpthread
#
target_link_libraries(${PROJECT_NAME} Cello pthread)