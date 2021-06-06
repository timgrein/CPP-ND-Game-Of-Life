#include "algo/GameOfLife.h"
#include "utils/Utils.h"

Grid2D<Cell> GameOfLife::GetNextGenGrid(Grid2D<Cell> *current_state_grid) {
    Grid2D<Cell> next_gen_grid(current_state_grid->GetNumberOfRows(), current_state_grid->GetNumberOfCols());

    for (int row = 0; row < current_state_grid->GetNumberOfRows(); row++) {
        for (int col = 0; col < current_state_grid->GetNumberOfCols(); col++) {
            bool next_gen_cell_state = GameOfLife::GetNextGenCellState(current_state_grid, row, col);
            Cell next_gen_cell(next_gen_cell_state);
            next_gen_grid(row, col) = next_gen_cell;
        }
    }

    return next_gen_grid;
}

int GameOfLife::CountLivingNeighbors(Grid2D<Cell> *current_state_grid, int cell_row, int cell_col) {
    int left = -1, top = -1, right = 2, bottom = 2;
    int sum_of_living_neighbors = 0;

    // cell is on left edge
    if (cell_col == 0) {
        left = 0;
    }

    // cell is on top edge
    if (cell_row == 0) {
        top = 0;
    }

    for (int row = top; row < bottom; row++) {
        for (int col = left; col < right; col++) {
            int cell_to_look_at_col = col + cell_col;
            int cell_to_look_at_row = row + cell_row;

            bool is_cell_outside_grid = cell_to_look_at_col > current_state_grid->GetNumberOfCols() - 1 ||
                                        cell_to_look_at_row > current_state_grid->GetNumberOfRows() - 1;
            bool is_itself = cell_row == cell_to_look_at_row && cell_col == cell_to_look_at_col;

            if (is_itself || is_cell_outside_grid) {
                continue;
            }

            if ((*current_state_grid)(cell_to_look_at_row, cell_to_look_at_col).IsAlive()) {
                sum_of_living_neighbors += 1;
            }
        }
    }

    return sum_of_living_neighbors;
}

bool GameOfLife::GetNextGenCellState(Grid2D<Cell> *current_state_grid, int cell_row, int cell_col) {
    int living_neighbors = GameOfLife::CountLivingNeighbors(current_state_grid, cell_row, cell_col);
    bool cell_is_alive = (*current_state_grid)(cell_row, cell_col).IsAlive();

    if (!cell_is_alive && living_neighbors == 3) {
        cell_is_alive = true;
    } else if (cell_is_alive && (living_neighbors < 2 || living_neighbors > 3)) {
        cell_is_alive = false;
    }

    return cell_is_alive;
}

bool GameOfLife::IsPopulationAlive(Grid2D<Cell> *current_state_grid) {
    for (int row = 0; row < current_state_grid->GetNumberOfRows(); row++) {
        for (int col = 0; col < current_state_grid->GetNumberOfCols(); col++) {
            if ((*current_state_grid)(row, col).IsAlive()) {
                return true;
            }
        }
    }

    return false;
}

void GameOfLife::Simulate(int grid_size, int number_of_generations,
                          const std::function<void(void)> &start_hook,
                          const std::function<void(int)> &loop_hook,
                          const std::function<void(void)> &end_hook,
                          const std::function<Cell(void)> &initial_state_supplier,
                          const Grid2DRenderer<Cell> &renderer,
                          std::chrono::milliseconds interval_between_generations) {
    start_hook();

    Grid2D<Cell> initial_state_grid(grid_size, grid_size, [initial_state_supplier]() -> Cell{ return initial_state_supplier();});
    renderer.Render(&initial_state_grid);

    Grid2D<Cell> next_gen_grid(grid_size, grid_size);

    for (int gen = 0; gen < number_of_generations; gen++) {
        loop_hook(gen);

        next_gen_grid = GetNextGenGrid(&initial_state_grid);
        renderer.Render(&next_gen_grid);

        if (!IsPopulationAlive(&next_gen_grid)) {
            end_hook();
            return;
        }

        initial_state_grid = std::move(next_gen_grid);

        std::this_thread::sleep_for(interval_between_generations);
    }

    end_hook();
}
