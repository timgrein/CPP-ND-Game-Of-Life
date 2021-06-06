#include <iostream>
#include <model/Cell.h>

#include "gtest/gtest.h"
#include "rendering/SimpleConsoleGrid2DRenderer.h"


class SimpleConsoleGrid2DRendererTest : public ::testing::Test{};

TEST_F(SimpleConsoleGrid2DRendererTest, TestRenderWithInts){
    Grid2D<int> grid(2,2);
    grid(0,0) = 1;
    grid(1,1) = 1;

    SimpleConsoleGrid2DRenderer<int> renderer;

    testing::internal::CaptureStdout();

    renderer.Render(&grid);

    std::string actual_output = testing::internal::GetCapturedStdout();
    std::string expected_output = "1  0\n0  1\n";

    EXPECT_EQ(expected_output, actual_output);
}

TEST_F(SimpleConsoleGrid2DRendererTest, TestRenderWithCells){
    Grid2D<Cell> grid(2, 2);
    grid(0,0) = Cell(true);
    grid(0,1) = Cell();
    grid(1,0) = Cell();
    grid(1,1) = Cell(true);

    SimpleConsoleGrid2DRenderer<Cell> renderer;

    testing::internal::CaptureStdout();

    renderer.Render(&grid);

    std::string actual_output = testing::internal::GetCapturedStdout();
    std::string expected_output =  "X  0\n0  X\n";

    EXPECT_EQ(expected_output, actual_output);
}