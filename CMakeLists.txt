cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.c header.h)
add_executable(143.reorder-list 143.reorder-list.c)
add_executable(35.fu-za-lian-biao-de-fu-zhi-lcof lcof/35.fu-za-lian-biao-de-fu-zhi-lcof.cpp)