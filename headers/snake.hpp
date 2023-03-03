#ifndef SNAKE_H
#define SNAKE_H

#include "canvas.hpp"
using std::pair;
using std::vector;
class Snake
{
    vector<pair<int, int>> positions;
    int direction;

public:
    Snake();
    ~Snake();
    friend class Game;
};

#endif