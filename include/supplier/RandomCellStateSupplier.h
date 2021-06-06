#ifndef GAMEOFLIFE_RANDOMCELLSTATESUPPLIER_H
#define GAMEOFLIFE_RANDOMCELLSTATESUPPLIER_H

#include "CellStateSupplier.h"
#include "model/Cell.h"

class RandomCellStateSupplier : public CellStateSupplier {
public:
    Cell Get() const;
};

#endif //GAMEOFLIFE_RANDOMCELLSTATESUPPLIER_H
