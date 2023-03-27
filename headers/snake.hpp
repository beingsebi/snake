#ifndef SNAKE_H
#define SNAKE_H

#include "constants.hpp"
#include <random>
#include <ostream>
#include <vector>
using std::ostream;
using std::pair;
using std::vector;

class Snake
{
    vector<pair<int, int>> positions;
    int direction;
    void move();
    void init();

public:
    Snake();
    ~Snake();
    void reset();
    friend ostream &operator<<(ostream &, const Snake &);
    friend class Game;
};

#endif