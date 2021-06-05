#include <gtest/gtest.h>
#include <Grid2D.h>

#include "Utils.h"

class Grid2DTest : public ::testing::Test {
};

TEST_F(Grid2DTest, GetElement) {
    Grid2D<int> grid(2, 2);
    grid(0,0) = 4;

    int actual_value_at_zero_zero = grid(0,0);
    int expected_value = 4;

    EXPECT_EQ(expected_value, actual_value_at_zero_zero);
}

TEST_F(Grid2DTest, TestRandomInitialization){

    // _grid with 400 elements -> probability of 0.5 ^ 400, that only ones or only zeros appear
    Grid2D<int> grid(20, 20, [] () -> int {return Utils::GetRandomOneOrZero();});

    bool at_least_one_zero_appears = false;
    bool at_least_one_one_appears = false;

    for(int row = 0; row < grid.GetNumberOfRows(); row++){
        for(int col = 0; col < grid.GetNumberOfCols(); col++){
            if(grid(row, col) == 0){
                at_least_one_zero_appears = true;
            } else if(grid(row, col) == 1){
                at_least_one_one_appears = true;
            }
        }
    }

    EXPECT_TRUE(at_least_one_one_appears);
    EXPECT_TRUE(at_least_one_zero_appears);
}