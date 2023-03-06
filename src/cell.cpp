#include "../headers/cell.hpp"
#include "../headers/constants.hpp"

#include <SFML/Graphics.hpp>

Cell::Cell(const int &x, const int &y, const bool b)
{
    this->rect.setSize(Constants::cell_size);
    this->set_coords(x, y);
    this->enabled = b;

    this->rect.setOutlineColor(Constants::color3);
    this->rect.setOutlineThickness(1.f);
    if (b)
        this->enable();
    else
        this->disable();
    //     {
    //         this->rect.setFillColor(Constants::color1);
    //     }
    //     else
    //     {
    //         this->rect.setFillColor(Constants::color4);
    //         this->rect.setOutlineThickness(0.f);
    //     }
}

void Cell::set_coords(const int &x, const int &y)
{
    // Y FIRST, X SECOND !!!
    this->rect.setPosition(static_cast<float>(1 + y * Constants::cell_size.y),
                           static_cast<float>(1 + x * Constants::cell_size.x));
}

void Cell::enable()
{
    this->enabled = 1;
    this->rect.setOutlineThickness(1.f);

    this->rect.setFillColor(Constants::color1);
    this->rect.setOutlineColor(Constants::color3);
}

void Cell::disable()
{
    this->enabled = 0;
    this->rect.setOutlineThickness(0.f);

    this->rect.setFillColor(Constants::color4);
    this->rect.setOutlineColor(Constants::color4);
}

bool Cell::is_enabled() const
{
    return enabled;
}
ostream &operator<<(ostream &os, const Cell &cell)
{
    os << "Top left coordinates: " << cell.rect.getPosition().x << "px " << cell.rect.getPosition().y << "px\n";
    os << "Width " << cell.rect.getSize().x << "px   Height " << cell.rect.getSize().y << "px\n";
    os << "Color rgba(" << static_cast<int>(cell.rect.getFillColor().r) << ",";
    os << static_cast<int>(cell.rect.getFillColor().g) << ",";
    os << static_cast<int>(cell.rect.getFillColor().b) << ",";
    os << static_cast<int>(cell.rect.getFillColor().a) << ")\n";
    return os;
}