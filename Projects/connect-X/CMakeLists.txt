cmake_minimum_required(VERSION 3.6)
project(connect_X)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES connectx.c)
add_executable(connect_X ${SOURCE_FILES})