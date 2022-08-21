cmake_minimum_required(VERSION 3.0.0)

project(geometry)

set(SOURCES
    Geometry.cpp
)

set(HEADERS 
    Geometry.h
)

add_library(geometry STATIC ${SOURCES} ${HEADERS})