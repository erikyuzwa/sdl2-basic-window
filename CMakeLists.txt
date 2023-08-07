cmake_minimum_required(VERSION 3.26)
project(sdl2_basic_window)

#set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# TODO: set this to YOUR sdl2 mingw path!
set(SDL2_PATH "D:/SDL2-2.28.2-mingw/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
