#include "gtest/gtest.h"
#include "Grid2D.h"
#include "Cell.h"
#include "GameOfLife.h"

// setup

class GameOfLifeTest : public ::testing::Test {
protected:
    std::unique_ptr<Grid2D<Cell>> _grid;

    virtual void SetUp() {
        /*
         * Grid:
         * 0  x  0
         * x  0  0
         * 0  x  x
         *
         * 0 = alive
         * x = dead
         */

        _grid = std::make_unique<Grid2D<Cell>>(3,3);

        (*_grid)(0, 0) = Cell(true);
        (*_grid)(0, 1) = Cell();
        (*_grid)(0, 2) = Cell(true);
        (*_grid)(1, 0) = Cell();
        (*_grid)(1, 1) = Cell(true);
        (*_grid)(1, 2) = Cell(true);
        (*_grid)(2, 0) = Cell(true);
        (*_grid)(2, 1) = Cell();
        (*_grid)(2, 2) = Cell();
    }
};


// normal case counting neighbors

TEST_F(GameOfLifeTest, count_living_neighbors_given_eight_possible_neighbors) {
    int cell_row = 1, cell_col = 1;

    int expected_number_of_living_neighbors = 4;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

// edge cases counting neighbors

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_left_edge) {
    int cell_row = 1, cell_col = 0;

    int expected_number_of_living_neighbors = 3;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_right_edge) {
    int cell_row = 1, cell_col = 2;

    int expected_number_of_living_neighbors = 2;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_top_edge) {
    int cell_row = 0, cell_col = 1;

    int expected_number_of_living_neighbors = 4;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_bottom_edge) {
    int cell_row = 2, cell_col = 1;

    int expected_number_of_living_neighbors = 3;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_top_left_corner) {
    int cell_row = 0, cell_col = 0;

    int expected_number_of_living_neighbors = 1;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_top_right_corner) {
    int cell_row = 0, cell_col = 2;

    int expected_number_of_living_neighbors = 2;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_bottom_left_corner) {
    int cell_row = 2, cell_col = 0;

    int expected_number_of_living_neighbors = 1;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

TEST_F(GameOfLifeTest, count_living_neighbors_given_cell_on_bottom_right_corner) {
    int cell_row = 2, cell_col = 2;

    int expected_number_of_living_neighbors = 2;
    int actual_number_of_living_neighbors = GameOfLife::CountLivingNeighbors(_grid.get(), cell_row, cell_col);

    EXPECT_EQ(expected_number_of_living_neighbors, actual_number_of_living_neighbors);
}

// next gen cell states tests

TEST_F(GameOfLifeTest, cell_will_get_alive_given_three_living_neighbors){
    int cell_row = 2, cell_col = 1;

    bool next_gen_cell_state = GameOfLife::GetNextGenCellState(_grid.get(), cell_row, cell_col);

    EXPECT_TRUE(next_gen_cell_state);
}

TEST_F(GameOfLifeTest, cell_will_die_given_one_living_neighbor){
    int cell_row = 0, cell_col = 0;

    bool next_gen_cell_state = GameOfLife::GetNextGenCellState(_grid.get(), cell_row, cell_col);

    EXPECT_FALSE(next_gen_cell_state);
}

TEST_F(GameOfLifeTest, cell_will_die_given_four_living_neighbors){
    int cell_row = 1, cell_col = 1;

    bool next_gen_cell_state = GameOfLife::GetNextGenCellState(_grid.get(), cell_row, cell_col);

    EXPECT_FALSE(next_gen_cell_state);
}

TEST_F(GameOfLifeTest, cell_will_stay_alive_given_two_living_neighbors){
    int cell_row = 1, cell_col = 2;

    bool next_gen_cell_state = GameOfLife::GetNextGenCellState(_grid.get(), cell_row, cell_col);

    EXPECT_TRUE(next_gen_cell_state);
}

// next gen grid state test

/*
*   old grid:
*   0  x  0
*   x  0  0
*   0  x  x
*
*   new grid:
*   x  x  0
*   0  x  0
*   x  0  x
*
*   0 = alive
*   x = dead
*
*   cells are counted from left to right
*/
TEST_F(GameOfLifeTest, new_grid_will_have_four_living_cell_given_grid_with_five_living_cells){
    Grid2D<Cell> next_gen_grid = GameOfLife::GetNextGenGrid(_grid.get());

    bool first_cell_is_alive = next_gen_grid(0,0).IsAlive();
    bool second_cell_is_alive = next_gen_grid(0,1).IsAlive();
    bool third_cell_is_alive = next_gen_grid(0,2).IsAlive();
    bool fourth_cell_is_alive = next_gen_grid(1,0).IsAlive();
    bool fifth_cell_is_alive = next_gen_grid(1,1).IsAlive();
    bool sixth_cell_is_alive = next_gen_grid(1,2).IsAlive();
    bool seventh_cell_is_alive = next_gen_grid(2,0).IsAlive();
    bool eigth_cell_is_alive = next_gen_grid(2,1).IsAlive();
    bool ninth_cell_is_alive = next_gen_grid(2,2).IsAlive();

    // first row
    EXPECT_FALSE(first_cell_is_alive);
    EXPECT_FALSE(second_cell_is_alive);
    EXPECT_TRUE(third_cell_is_alive);

    // second row
    EXPECT_TRUE(fourth_cell_is_alive);
    EXPECT_FALSE(fifth_cell_is_alive);
    EXPECT_TRUE(sixth_cell_is_alive);

    // third row
    EXPECT_FALSE(seventh_cell_is_alive);
    EXPECT_TRUE(eigth_cell_is_alive);
    EXPECT_FALSE(ninth_cell_is_alive);
}

// is population alive tests

TEST_F(GameOfLifeTest, population_should_be_alive_given_grid_with_five_living_cells){
    EXPECT_TRUE(GameOfLife::IsPopulationAlive(_grid.get()));
}

TEST_F(GameOfLifeTest, population_should_be_dead_given_grid_without_living_cells){
    Grid2D<Cell> grid_without_living_cells(2,2);

    grid_without_living_cells(0,0) = Cell();
    grid_without_living_cells(0,1) = Cell();
    grid_without_living_cells(1,0) = Cell();
    grid_without_living_cells(1,1) = Cell();

    EXPECT_FALSE(GameOfLife::IsPopulationAlive(&grid_without_living_cells));
}