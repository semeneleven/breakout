cmake_minimum_required(VERSION 3.0.0)

project(geometry)

set(SOURCES
    Box.cpp
    Point.cpp
    Vector.cpp
    Line.cpp
)

set(HEADERS 
    Box.h
    Point.h
    Vector.h
    Line.h
)

add_library(geometry STATIC ${SOURCES} ${HEADERS})