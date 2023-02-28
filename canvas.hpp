#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include <vector>
using std::vector;
class Canvas
{
    int lines;
    int columns;
    vector<vector<Cell>> matrix;
};

#endif