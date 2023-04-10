#include "../headers/canvas.hpp"

Canvas::Canvas()
{
    this->init();
}

void Canvas::init()
{
    this->matrix.clear();
    this->disabled_cells.clear();
    static std::mt19937 mt(time(nullptr));
    for (int i = 0, ax; i < Constants::lines; i++)
    {
        this->matrix.push_back(vector<Cell>());
        // matrix.back().reserve(Constants::columns);
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

bool Canvas::is_disabled(const pair<int, int> &p) const
{
    for (const auto &i : this->disabled_cells)
        if (i == p)
            return 1;
    return 0;
}

ostream &operator<<(ostream &os, const Canvas &canv)
{
    os << "1 - free square;  0 - wall:\n";
    for (const auto &i : canv.matrix)
    {
        for (const auto &j : i)
            os << j.is_enabled() << ' ';
        os << '\n';
    }
    return os;
}

vector<vector<Cell>> Canvas::get_matrix() const
{
    return this->matrix;
}
