#include <Grid2D.h>
#include <Cell.h>

template<typename T>
Grid2D<T>::Grid2D(int rows, int columns) : _rows(rows), _columns(columns), _entries(rows * columns) {}

template <typename T>
Grid2D<T>::Grid2D(int rows, int columns, std::function<T(void)> random_generator) : Grid2D<T>(rows, columns){
    for(int row = 0; row < this->GetNumberOfRows(); row++){
        for(int col = 0; col < this->GetNumberOfCols(); col++){
            (*this)(row, col) = random_generator();
        }
    }
}

template<typename T>
T &Grid2D<T>::operator()(int row, int column) {
    return _entries[(row * _columns) + column];
}

template<typename T>
T Grid2D<T>::operator()(int row, int column) const {
    return _entries[(row * _columns) + column];
}

template<typename T>
int Grid2D<T>::GetNumberOfCols() const {
    return _columns;
}

template<typename T>
int Grid2D<T>::GetNumberOfRows() const{
    return _rows;
}

// move constructor
template<typename T>
Grid2D<T>::Grid2D(Grid2D &&other) : _entries(std::move(other._entries)) {
}


// move assignment operator
template<typename T>
Grid2D<T> &Grid2D<T>::operator=(Grid2D &&other) {
    _entries = std::move(other._entries);
    return *this;
}

template class Grid2D<int>;
template class Grid2D<Cell>;