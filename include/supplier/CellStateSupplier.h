#ifndef GAMEOFLIFE_CELLSTATESUPPLIER_H
#define GAMEOFLIFE_CELLSTATESUPPLIER_H

class CellStateSupplier{
public:
    virtual Cell Get() const = 0;
};

#endif //GAMEOFLIFE_CELLSTATESUPPLIER_H
