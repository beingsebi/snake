#ifndef SNAKE_H
#define SNAKE_H

#include "canvas.hpp"
using std::pair;
using std::vector;
class Snake
{
    vector<pair<int, int>> v;
    Canvas *c;
};

#endif