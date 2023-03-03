#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>
#include <vector>
struct Constants
{
    static sf::Vector2f const cell_size;

    static sf::Color const color1;
    static sf::Color const color2;
    static sf::Color const color3;
    static sf::Color const color4;
    static sf::Color const color5;
    static sf::Color const color6;

    static int const lines;
    static int const columns;
    static std::vector<std::pair<int, int>> const directions;
};

#endif