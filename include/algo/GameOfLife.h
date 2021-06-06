#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#include <thread>
#include <functional>

#include "model/Grid2D.h"
#include "model/Cell.h"
#include "rendering/Grid2DRenderer.h"
#include "rendering/SimpleConsoleGrid2DRenderer.h"
#include "hooks/DefaultSimulationHooks.h"
#include "supplier/RandomCellStateSupplier.h"

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
                  const std::function<void(void)> &start_hook = []() -> void { DefaultSimulationHooks().StartHook(); },
                  const std::function<void(int)> &loop_hook = [](int current_generation) -> void {DefaultSimulationHooks().LoopHook(current_generation);},
                  const std::function<void(void)> &end_hook = []() -> void { DefaultSimulationHooks().EndHook(); },
                  const std::function<Cell(void)> &initial_state_supplier = []() -> Cell { return RandomCellStateSupplier().Get(); },
                  const Grid2DRenderer<Cell> &renderer = SimpleConsoleGrid2DRenderer<Cell>(),
                  std::chrono::milliseconds interval_between_generations = std::chrono::milliseconds(1000));
}

#endif //GAMEOFLIFE_GAMEOFLIFE_H
