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
    friend class Game;
};

#endif