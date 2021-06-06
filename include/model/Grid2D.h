#ifndef GAMEOFLIFE_GRID2D_H
#define GAMEOFLIFE_GRID2D_H

#include <functional>
#include <vector>

template<typename T>
class Grid2D {
public:
    Grid2D(int rows, int columns);

    // constructor with state_supplier function to be able to initialize a grid (f.e. with a random state)
    Grid2D(int rows, int columns, std::function<T(void)> state_supplier);

    // move constructor
    Grid2D(Grid2D &&other);

    // move assignment operator
    Grid2D &operator=(Grid2D &&other);

    T &operator()(int row, int column);

    T operator()(int row, int column) const;

    int GetNumberOfCols() const;
    int GetNumberOfRows() const;

private:
    std::vector<T> _entries;
    int _rows;
    int _columns;
};

#endif //GAMEOFLIFE_GRID2D_H
