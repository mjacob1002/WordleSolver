cmake_minimum_required(VERSION 3.10)
project(WordleSolver)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
include_directories(include/)

add_compile_options(-pthread)
if(UNIX)
	message(STATUS "UNIX OPERATING SYSTEM")
endif()

message("BUILDING THE FILTER TEST EXECUTABLE")
add_executable(filter_test tests/filter_test.cpp src/filter.cpp)


add_executable(wordle_solve src/driver.cc src/read.cpp src/bot.cpp src/game.cpp src/filter.cpp)

add_executable(test_Game src/read.cpp src/bot.cpp src/game.cpp src/filter.cpp tests/game_test.cpp)

add_executable(evaluate src/read.cpp src/bot.cpp src/game.cpp src/filter.cpp src/simulate.cpp)
