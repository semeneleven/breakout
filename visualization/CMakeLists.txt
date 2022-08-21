cmake_minimum_required(VERSION 3.0.0)

project(visualization)

set(HEADERS 
    Canvas.h
)

set(SOURCES
    Canvas.cpp
)

add_library(visualization STATIC ${SOURCES} ${HEADERS})
target_link_libraries(visualization geometry)