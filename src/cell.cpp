#include "../headers/cell.hpp"

Cell::Cell(const int &x, const int &y, const bool b)
{
    this->rect.setSize(Constants::cell_size);
    this->set_coords(x, y);
    this->enabled = b;

    // this->rect.setOutlineColor(Constants::border_color);
    this->rect.setOutlineThickness(1.f);
    if (b)
        this->enable();
    else
        this->disable();
}

Cell::Cell(const Cell &other) : rect{other.rect}, enabled{other.enabled} {}

void Cell::set_coords(const int &x, const int &y)
{
    // Y FIRST, X SECOND !!!
    this->rect.setPosition(static_cast<float>(1 + y * Constants::cell_size.y),
                           static_cast<float>(1 + x * Constants::cell_size.x));
}

void Cell::enable()
{
    this->enabled = 1;
    // this->rect.setOutlineThickness(1.f);
    // this->rect.setFillColor(Constants::cell_color);
    // this->rect.setOutlineColor(Constants::border_color);
}

void Cell::disable()
{
    this->enabled = 0;
    // this->rect.setOutlineThickness(1.f);
    // this->rect.setFillColor(Constants::disabled_color);
    // this->rect.setOutlineColor(Constants::disabled_color);
}

sf::RectangleShape Cell::get_rect() const
{
    return this->rect;
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