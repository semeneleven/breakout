cmake_minimum_required(VERSION 3.0.0)

project(breakout VERSION 0.1.0)

set(SOURCES
    main.cpp
    Application.cpp
    GameView.cpp
)

add_executable(breakout ${SOURCES})

add_subdirectory(geometry)
add_subdirectory(visualization)

target_link_libraries(breakout geometry visualization)
