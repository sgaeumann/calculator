cmake_minimum_required(VERSION 3.10)
project(tp1) # init
set(CMAKE_CXX_STANDARD 14) # set minimum CMake version, independant of compiler
add_executable(tp1 src/main.cpp
        src/calculator.cpp) # specify an executable and its files
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") # enable -Wall to show all warnings