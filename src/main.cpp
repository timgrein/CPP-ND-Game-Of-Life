#include <iostream>
#include <thread>
#include <SimpleConsoleGrid2DRenderer.h>
#include <Cell.h>
#include <GameOfLife.h>

int main() {
    int grid_size = 10;
    int number_of_generations = 10;

    GameOfLife::Simulate(grid_size, number_of_generations);

    return 0;
}