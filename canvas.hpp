#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include <vector>
using std::vector;
class Canvas
{
    vector<vector<Cell>> matrix;

public:
    Canvas();
    vector<vector<Cell>> get_matrix() const;
};

#endif