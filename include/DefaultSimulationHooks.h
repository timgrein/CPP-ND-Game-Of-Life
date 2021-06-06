#ifndef GAMEOFLIFE_DEFAULTSIMLUATIONHOOKS_H
#define GAMEOFLIFE_DEFAULTSIMLUATIONHOOKS_H

#include "SimulationHooks.h"

class DefaultSimulationHooks : public SimulationHooks {
public:
    void StartHook() const;
    void LoopHook(int current_generation) const;
    void EndHook() const;
};

#endif //GAMEOFLIFE_DEFAULTSIMLUATIONHOOKS_H
