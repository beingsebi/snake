#ifndef SNAKE_H
#define SNAKE_H

#include "canvas.hpp"
using std::pair;
using std::vector;
class snake
{
    vector<pair<int, int>> v;
    canvas *c;
};

#endif