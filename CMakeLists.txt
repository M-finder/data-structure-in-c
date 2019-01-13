cmake_minimum_required(VERSION 3.13)
project(c C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

set(SOURCE_FILES main.c)
add_executable(main ${SOURCE_FILES})