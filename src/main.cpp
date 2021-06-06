#include <iostream>

#include <algo/GameOfLife.h>

int main() {
    int grid_size = 10;
    int number_of_generations = 5;

    // default example
    GameOfLife::Simulate(grid_size, number_of_generations);

    // custom lambda hooks example
    GameOfLife::Simulate(grid_size, number_of_generations,
                         []() -> void {
                             std::cout << "Custom start hook: started simulation" << std::endl;
                         },
                         [](int current_generation) -> void {
                             std::cout << "Custom Loop hook: current generation #" << (current_generation + 1)
                                       << std::endl;
                         },
                         []() -> void {
                             std::cout << "Custom end hook: ended simulation" << std::endl;
                         });

    // custom lambda cell state supplier example
    GameOfLife::Simulate(grid_size, number_of_generations,
                         []() -> void { DefaultSimulationHooks().StartHook(); },
                         [](int current_generation) -> void { DefaultSimulationHooks().LoopHook(current_generation); },
                         []() -> void { DefaultSimulationHooks().EndHook(); },
                         []() -> Cell { return Cell(true); });

    return 0;
}