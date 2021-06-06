#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

#include <string>
#include <iostream>

class Cell{
public:
    Cell();
    Cell(bool is_alive);

    bool IsAlive() const;

    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& out, const Cell& cell);

private:
    bool _is_alive;
};

#endif //GAMEOFLIFE_CELL_H
