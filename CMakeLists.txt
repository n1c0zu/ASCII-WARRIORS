cmake_minimum_required(VERSION 3.29)
project(ASCII_WARRIORS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ASCII_WARRIORS
    core.c
    core.h
    database.h
    gatcga.c
    inventory.h
    menu.c
    menu.h
    save.h
        combat.c
        combat.h
        combat.h)
