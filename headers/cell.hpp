#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
class Cell
{
    sf::RectangleShape rect;
    bool enabled;

public:
    Cell(const int &, const int &, const bool);
    void set_coords(const int &, const int &);
    void enable();
    void disable();
    friend class Game;
};

#endif