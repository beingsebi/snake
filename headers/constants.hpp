#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>
#include "exceptions.hpp"

using std::pair;
using std::string;
using std::vector;

struct Constants
{
    static sf::Vector2f const cell_size;

    static sf::Color const cell_color[4];
    static sf::Color const border_color[4];
    static sf::Color const disabled_color[4];
    static sf::Color const body_color[4];
    static sf::Color const head_color[4];

    static int const lines;
    static int const columns;
    static vector<pair<int, int>> const directions;
    static vector<string> const ev_paths;
    static pair<int, int> const NO_DISABLED;
    static int const bonus_score;
    static int const bonus_mod;
    static int const key_score;
    static string const HIGH_SCORE_PATH;
    static int const prob_key;
    static int const prob_flower;
    static int const prob_fruit;
    static int const prob_egg;

    enum Directions
    {
        down,
        left,
        up,
        right
    };

    enum Events
    {
        apple,
        watermelon,
        pear,
        key,
        bluef,
        yellowf,
        redf,
        purplef
    };

    enum Themes
    {
        blue,
        yellow,
        red,
        purple
    };
};

#endif