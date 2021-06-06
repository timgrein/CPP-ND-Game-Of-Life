cmake_minimum_required(VERSION 3.7)

project(GameOfLife)
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include)
file(GLOB SOURCES "src/*.cpp" "src/hooks/*.cpp" "src/model/*.cpp" "src/rendering/*.cpp" "src/utils/*.cpp" "src/algo/*.cpp" "src/supplier/*.cpp")

add_subdirectory(thirdparty/googletest)
add_executable(test test/grid_2D_test.cpp src/model/Grid2D.cpp
                    test/utils_test.cpp src/utils/Utils.cpp
                    test/simple_console_grid_2d_renderer_test.cpp src/rendering/SimpleConsoleGrid2DRenderer.cpp src/model/Cell.cpp
                    test/game_of_life_test.cpp src/algo/GameOfLife.cpp)
target_link_libraries(test gtest_main)


add_executable(GameOfLife ${SOURCES})
