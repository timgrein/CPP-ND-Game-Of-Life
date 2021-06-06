#include <iostream>
#include <algo/GameOfLife.h>

int main() {
    int grid_size = 10;
    int number_of_generations = 10;

    // default
    GameOfLife::Simulate(grid_size, number_of_generations);

    // custom hooks
    GameOfLife::Simulate(grid_size, number_of_generations,
                         []() -> void {
                             std::cout << "Custom start hook: started simulation" << std::endl;
                         },
                         [](int current_generation) -> void {
                             std::cout << "Custom Loop hook: current generation #" << (current_generation + 1) << std::endl;
                         },
                         []() -> void {
                             std::cout << "Custom end hook: ended simulation" << std::endl;
                         });



    return 0;
}