cmake_minimum_required(VERSION 3.17)
project(wet3_files)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ts1 selfTests/ts1.cpp Code_Skeleton/Part1/Headers.hpp Code_Skeleton/Part1/Semaphore.cpp)
add_executable(Code_Skeleton/Part1/PCQueue.cpp)
add_executable(wet3_files main.cpp)