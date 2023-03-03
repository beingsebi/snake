#include "canvas.hpp"
#include "constants.hpp"

Canvas::Canvas()
{
    for (int i = 0; i < Constants::lines; i++)
    {
        this->matrix.push_back(vector<Cell>());
        for (int j = 0; j < Constants::columns; j++)
            this->matrix[i].push_back(Cell(i, j, 1));
    }
}

vector<vector<Cell>> Canvas::get_matrix() const
{
    return this->matrix;
}