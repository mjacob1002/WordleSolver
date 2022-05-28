cmake_minimum_required(VERSION 3.10)
project(WordleSolver)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
include_directories(include/)

if(UNIX)
	message(STATUS "UNIX OPERATING SYSTEM")
endif()
message("READ")

add_executable(wordle_solve src/driver.cc src/read.cpp)
