cmake_minimum_required(VERSION 3.23)
project(TD2S2_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TD2S2_POO
        main.cpp
        Point.cpp
        Point.h
        Droite.cpp
        Droite.h
        col_point.cpp
        col_point.h)
