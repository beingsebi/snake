#ifndef SNAKE_H
#define SNAKE_H

#include "constants.hpp"
#include <random>
#include <ostream>
#include <vector>
#include <cassert>
using std::ostream;
using std::pair;
using std::vector;

class Snake
{
    vector<pair<int, int>> positions;
    int direction;

public:
    void init();
    void move();
    Snake();
    ~Snake();
    void reset();
    int get_direction() const;
    void set_direction(const int &);
    bool is_outside() const;
    size_t getp_size() const;
    friend ostream &operator<<(ostream &, const Snake &);
    pair<int, int> &operator[](size_t);
};

#endif