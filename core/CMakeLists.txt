cmake_minimum_required(VERSION 3.0.0)

project(breakout_core)

set(SOURCES
    Game.cpp
)

set(HEADERS 
    Game.h
)

add_library(breakout_core STATIC ${SOURCES} ${HEADERS})
target_link_libraries(breakout_core visualization)