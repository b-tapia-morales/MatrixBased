cmake_minimum_required(VERSION 3.26)
project(MatrixBased C)

set(CMAKE_C_STANDARD 90)

add_executable(MatrixBased main.c matrix_traversal.h matrix_operations.h defines.h)
