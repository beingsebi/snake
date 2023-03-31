#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include "constants.hpp"
#include <random>
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
    void init();
    vector<vector<Cell>> get_matrix() const;
    bool is_disabled(const pair<int, int> &) const;
    friend ostream &operator<<(ostream &, const Canvas &);
};

#endif