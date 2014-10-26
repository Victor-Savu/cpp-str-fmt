project(FormatStrings)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
add_definitions(-std=c++1z -Wall -Wextra -Werror)
set(SRC_LIST ${SRC_LIST} format_string.hh str.hh algo.hh)

add_executable(${PROJECT_NAME} ${SRC_LIST})

