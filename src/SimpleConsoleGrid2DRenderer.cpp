#include <string>
#include <iostream>
#include <Cell.h>

#include "SimpleConsoleGrid2DRenderer.h"

template<typename T>
void SimpleConsoleGrid2DRenderer<T>::Render(Grid2D<T>* grid) const {
    for(int row = 0; row < grid->GetNumberOfRows(); row++){
        for(int col = 0; col < grid->GetNumberOfCols(); col++){
            std::cout << (*grid)(row, col);
            bool is_not_last_col = col != (grid->GetNumberOfCols() - 1);
            if(is_not_last_col){
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

template class SimpleConsoleGrid2DRenderer<int>;
template class SimpleConsoleGrid2DRenderer<Cell>;