#include "canvas.hpp"
#include "constants.hpp"
#include <random>
#include <ctime>

Canvas::Canvas()
{
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < Constants::lines; i++)
    {
        this->matrix.push_back(vector<Cell>());
        for (int j = 0; j < Constants::columns; j++)
            this->matrix[i].push_back(Cell(i, j,
                                           (((mt() % 11) != 0) | (i == 0) | (j == 0) | (i == Constants::lines - 1) | (j == Constants::columns - 1))));
    }
}

vector<vector<Cell>> Canvas::get_matrix() const
{
    return this->matrix;
}