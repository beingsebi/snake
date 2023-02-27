#ifndef CANVAS_H
#define CANVAS_H

#include "cell.hpp"
#include <vector>
using std::vector;
class canvas
{
    int lines;
    int columns;
    vector<vector<cell>> matrix;
};

#endif