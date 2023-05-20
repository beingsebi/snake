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
    int direction, to_grow = 0;

    Snake();

public:
    Snake(const Snake &) = delete;
    Snake operator=(const Snake &) = delete;
    static Snake &get_snake();
    void init();
    void move();
    ~Snake();
    void reset();
    int get_direction() const;
    void set_direction(const int &);
    bool is_outside() const;
    size_t getp_size() const;
    void add_grow(int);
    friend ostream &operator<<(ostream &, const Snake &);
    pair<int, int> &operator[](size_t);
};

#endif