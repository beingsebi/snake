#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"
using std::ostream;

class Cell
{
    sf::RectangleShape rect;
    bool enabled;

public:
    Cell() = default;
    Cell(const Cell &);

    Cell(const int &, const int &, const bool);
    void set_coords(const int &, const int &);
    sf::RectangleShape get_rect() const;
    void enable();
    void disable();
    bool is_enabled() const;
    friend ostream &operator<<(ostream &, const Cell &);
};

#endif