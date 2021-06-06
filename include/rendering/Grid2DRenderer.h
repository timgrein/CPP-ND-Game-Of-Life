#ifndef GAMEOFLIFE_GRIDRENDERER_H
#define GAMEOFLIFE_GRIDRENDERER_H

#include "model/Grid2D.h"

template <typename T>
class Grid2DRenderer{
public:
    virtual void Render(Grid2D<T>* grid) const = 0;
};

#endif //GAMEOFLIFE_GRIDRENDERER_H
