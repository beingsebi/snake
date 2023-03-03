#include "cell.hpp"
#include "constants.hpp"

#include <SFML/Graphics.hpp>

Cell::Cell(const int &x, const int &y, const bool b)
{
    this->rect.setSize(Constants::cell_size);
    this->set_coords(x, y);
    this->enabled = b;

    this->rect.setOutlineColor(Constants::color3);
    this->rect.setOutlineThickness(1.f);
    if (b)
    {
        this->rect.setFillColor(Constants::color1);
    }
    else
    {
        this->rect.setFillColor(Constants::color4);
    }
}

sf::RectangleShape Cell::get_rect() const
{
    return this->rect;
}

void Cell::set_coords(const int &x, const int &y)
{
    this->rect.setPosition(static_cast<float>(1 + x * Constants::cell_size.x),
                           static_cast<float>(1 + y * Constants::cell_size.y));
}
void Cell::enable()
{
    this->enabled = 1;
    this->rect.setFillColor(Constants::color1);
    this->rect.setOutlineColor(Constants::color3);
}
void Cell::disable()
{
    this->enabled = 0;
    this->rect.setFillColor(Constants::color4);
    this->rect.setOutlineColor(Constants::color4);
}