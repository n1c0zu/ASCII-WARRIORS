cmake_minimum_required(VERSION 3.29)
project(ASCII_WARRIORS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ASCII_WARRIORS
    gatcga.c
    core.c
    core.h
    database.h
    inventory.h
    save.h
    combat.h
    menu.h
    party.h
)
