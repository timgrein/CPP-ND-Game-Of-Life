cmake_minimum_required(VERSION 3.7)

project(GameOfLife)
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_subdirectory(thirdparty/googletest)
add_executable(test test/grid_2D_test.cpp src/Grid2D.cpp
                    test/utils_test.cpp src/Utils.cpp
                    test/simple_console_grid_2d_renderer_test.cpp src/SimpleConsoleGrid2DRenderer.cpp src/Cell.cpp
                    test/game_of_life_test.cpp src/GameOfLife.cpp)
target_link_libraries(test gtest_main)


add_executable(GameOfLife ${SOURCES})
