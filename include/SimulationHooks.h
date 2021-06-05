#ifndef GAMEOFLIFE_SIMULATIONHOOKS_H
#define GAMEOFLIFE_SIMULATIONHOOKS_H

namespace SimulationHooks {

    namespace StartHooks {
        void CoutSimulationStarted();
    }

    namespace LoopHooks {
        void CoutCurrentGenerationInfo(int current_generation);
    }

    namespace EndHooks {
        void CoutSimulationEnded();
    }


}

#endif //GAMEOFLIFE_SIMULATIONHOOKS_H
