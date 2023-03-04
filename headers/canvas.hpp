#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include <vector>
using std::ostream;
using std::pair;
using std::vector;

class Canvas
{
    vector<vector<Cell>> matrix;
    vector<pair<int, int>> disabled_cells;

public:
    Canvas();
    bool is_disabled(const pair<int, int> &) const;
    friend ostream &operator<<(ostream &, const Canvas &);
    friend class Game;
};

#endif