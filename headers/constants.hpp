#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>
struct Constants
{
    static sf::Vector2f const cell_size;

    static sf::Color const cell_color;
    static sf::Color const color2;
    static sf::Color const border_color;
    static sf::Color const disabled_color;
    static sf::Color const body_color;
    static sf::Color const head_color;

    static int const lines;
    static int const columns;
    static std::vector<std::pair<int, int>> const directions;

    enum Directions
    {
        down,
        left,
        up,
        right
    };
};

#endif