cmake_minimum_required(VERSION 3.16)

project(cpu6502mulator)

add_library(cpu6502mulator 
    src/cpu.cpp
)

target_include_directories(cpu6502mulator PRIVATE src/)
target_include_directories(cpu6502mulator PUBLIC include/)