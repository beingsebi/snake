#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>
#include <ostream>
using std::ostream;
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
    friend ostream &operator<<(ostream &, const Snake &);
    friend class Game;
};

#endif