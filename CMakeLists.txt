cmake_minimum_required(VERSION 3.17)
project(Bataille_naval C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Bataille_naval
        main.c
        Menu_functions.h
        structs.h game_fuctions.h)
