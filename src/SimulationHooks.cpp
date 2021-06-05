#include <iostream>

#include "SimulationHooks.h"

void SimulationHooks::StartHooks::CoutSimulationStarted() {
    std::cout << "Started simulation" << std::endl;
}

void SimulationHooks::LoopHooks::CoutCurrentGenerationInfo(int current_generation) {
    std::cout << "Current generation: #" << (current_generation + 1) << std::endl;
}

void SimulationHooks::EndHooks::CoutSimulationEnded() {
    std::cout << "Started simulation" << std::endl;
}

