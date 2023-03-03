#ifndef SNAKE_H
#define SNAKE_H

#include "canvas.hpp"
using std::pair;
using std::vector;
class Snake
{
    vector<pair<int, int>> v;

public:
    Snake();
    ~Snake();
    Snake(const vector<pair<int, int>>);
};

#endif