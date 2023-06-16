cmake_minimum_required(VERSION 3.10)
project(clox)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_executable(clox main.c chunk.c memory.c debug.c)

target_include_directories(clox PRIVATE ${CMAKE_SOURCE_DIR})
