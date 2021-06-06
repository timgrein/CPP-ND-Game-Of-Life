#ifndef GAMEOFLIFE_SIMPLECONSOLEGRID2DRENDERER_H
#define GAMEOFLIFE_SIMPLECONSOLEGRID2DRENDERER_H

#include "rendering/Grid2DRenderer.h"

template <typename T>
class SimpleConsoleGrid2DRenderer : public Grid2DRenderer<T>{
public:
    void Render(Grid2D<T>* grid) const;
};

#endif //GAMEOFLIFE_SIMPLECONSOLEGRID2DRENDERER_H
