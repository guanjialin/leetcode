cmake_minimum_required(VERSION 3.11)
project(leetcode)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.c header.h)
add_executable(143.reorder-list 143.reorder-list.c)
add_executable(35.fu-za-lian-biao-de-fu-zhi-lcof lcof/35.fu-za-lian-biao-de-fu-zhi-lcof.cpp)
add_executable(430.flatten-a-multilevel-doubly-linked-list 430.flatten-a-multilevel-doubly-linked-list.cpp)
add_executable(925.long-pressed-name 925.long-pressed-name.c)
add_executable(1171.remove-zero-sum-consecutive-nodes-from-linked-list 1171.remove-zero-sum-consecutive-nodes-from-linked-list.cpp)

add_executable(725.split-linked-list-in-parts 725.split-linked-list-in-parts.cpp)
add_executable(763.partition-labels 763.partition-labels.c)
add_executable(02.04.partition-list-lcci lcci/02.04.partition-list-lcci.c)