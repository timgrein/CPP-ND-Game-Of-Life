#include "model/Cell.h"

Cell::Cell() : _is_alive(false) {}

Cell::Cell(bool is_alive) : _is_alive(is_alive) {}

bool Cell::IsAlive() const {
    return _is_alive;
}

// 😁 || 💀
Cell::operator std::string() const {
    return Cell::IsAlive() ? "X" : "0";
}

std::ostream& operator<<(std::ostream &out, const Cell &cell) {
    return out << std::string(cell);
}
