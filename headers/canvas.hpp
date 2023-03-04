#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include <vector>
#include <utility>
using std::pair;
using std::vector;
class Canvas
{
    vector<vector<Cell>> matrix;
    vector<pair<int, int>> disabled_cells;

public:
    Canvas();
    bool is_disabled(const pair<int, int> &) const;
    friend class Game;
};

#endif