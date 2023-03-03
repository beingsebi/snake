#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
class Cell
{
    sf::RectangleShape rect;
    bool enabled;

public:
    Cell(const int &, const int &, const bool);
    sf::RectangleShape get_rect() const;
    void set_coords(const int &, const int &);
    void enable();
    void disable();
};

#endif