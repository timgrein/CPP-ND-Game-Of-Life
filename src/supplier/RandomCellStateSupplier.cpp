#include "model/Cell.h"
#include "supplier/RandomCellStateSupplier.h"
#include "utils/Utils.h"

Cell RandomCellStateSupplier::Get() const {
    return Utils::GetRandomOneOrZero() == 0 ? Cell() : Cell(true);
}