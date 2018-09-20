cmake_minimum_required(VERSION 3.12)
project(file_utils C)

set(CMAKE_C_STANDARD 99)

add_executable(file_utils reverse.c file_utils.h file_utils.c)