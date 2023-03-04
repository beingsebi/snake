#ifndef SNAKE_H
#define SNAKE_H

#include "canvas.hpp"
using std::pair;
using std::vector;
class Snake
{
    vector<pair<int, int>> positions;
    int direction;
    void move();

public:
    Snake();
    ~Snake();
    void reset();
    friend class Game;
};

#endif