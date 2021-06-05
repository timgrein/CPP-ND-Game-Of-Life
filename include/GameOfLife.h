#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#include <thread>
#include <functional>

#include "Grid2D.h"
#include "Cell.h"
#include "Grid2DRenderer.h"
#include "SimpleConsoleGrid2DRenderer.h"
#include "SimulationHooks.h"

namespace GameOfLife {
    Grid2D<Cell> GetNextGenGrid(Grid2D<Cell> *current_state_grid);

    int CountLivingNeighbors(Grid2D<Cell> *current_state_grid, int cell_row, int cell_col);

    bool GetNextGenCellState(Grid2D<Cell> *current_state_grid, int cell_row, int cell_col);

    bool IsPopulationAlive(Grid2D<Cell> *current_state_grid);

    /*
     * simulation method, which provides several hooks to add additional features to the
     * simulation (default hooks print information to the console)
     */
    void Simulate(int grid_size,
                  int number_of_generations,
                  const std::function<void(void)> &start_hook =
                          []() -> void { SimulationHooks::StartHooks::CoutSimulationStarted(); },
                  const std::function<void(int)> &simulation_loop_hook =
                          [](int current_generation) -> void {SimulationHooks::LoopHooks::CoutCurrentGenerationInfo(current_generation);},
                  const std::function<void(void)> &end_hook =
                          []() -> void { SimulationHooks::EndHooks::CoutSimulationEnded(); },
                  const Grid2DRenderer<Cell> &renderer = SimpleConsoleGrid2DRenderer<Cell>(),
                  std::chrono::milliseconds interval_between_generations = std::chrono::milliseconds(1000));
}

#endif //GAMEOFLIFE_GAMEOFLIFE_H
