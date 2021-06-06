#ifndef GAMEOFLIFE_SIMULATIONHOOKS_H
#define GAMEOFLIFE_SIMULATIONHOOKS_H

class SimulationHooks {
public:
    virtual void StartHook() const = 0;

    virtual void LoopHook(int current_generation) const = 0;

    virtual void EndHook() const = 0;

};

#endif //GAMEOFLIFE_SIMULATIONHOOKS_H
