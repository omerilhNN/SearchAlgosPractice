cmake_minimum_required(VERSION 3.26)
project(SearchAlgosPractice C)

set(CMAKE_C_STANDARD 11)

add_library(SearchAlgosPractice library.c
        LinearSearch.c)
