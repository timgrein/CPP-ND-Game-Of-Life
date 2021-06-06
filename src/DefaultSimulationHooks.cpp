#include "DefaultSimulationHooks.h"

#include <iostream>

void DefaultSimulationHooks::StartHook() const {
    std::cout << "Started simulation" << std::endl;
}

void DefaultSimulationHooks::LoopHook(int current_generation) const {
    std::cout << "Current generation #" << (current_generation + 1) << std::endl;
}

void DefaultSimulationHooks::EndHook() const {
    std::cout << "Ended simulation" << std::endl;
}