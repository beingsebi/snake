#include "canvas.hpp"
#include "constants.hpp"
#include <random>
#include <ctime>

Canvas::Canvas()
{
    std::mt19937 mt(time(nullptr));
    for (int i = 0, ax; i < Constants::lines; i++)
    {
        this->matrix.push_back(vector<Cell>());
        matrix.back().reserve(Constants::columns);
        for (int j = 0; j < Constants::columns; j++)
        {
            ax = (((mt() % 11) != 0) | (i == 0) | (j == 0) | (i == Constants::lines - 1) | (j == Constants::columns - 1));
            if (ax)
                this->matrix[i].push_back(Cell(i, j, 1));
            else
                this->matrix[i].push_back(Cell(i, j, 0)),
                    this->disabled_cells.push_back({i, j});
        }
    }
}