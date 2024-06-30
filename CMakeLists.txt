cmake_minimum_required(VERSION 3.24)

project(Sum_24_Alex_WuLiu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)
add_subdirectory(Farming)
add_subdirectory(Sum_24_Alex_WuLiu)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT BestGame)