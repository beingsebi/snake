#include "../headers/constants.hpp"

int const Constants::lines = 15;
int const Constants::columns = 20;

sf::Vector2f const Constants::cell_size = sf::Vector2f(40.f, 40.f);

sf::Color const Constants::cell_color = sf::Color(34, 40, 49, 255);
sf::Color const Constants::border_color = sf::Color(0, 173, 181, 255);
sf::Color const Constants::disabled_color = sf::Color(238, 238, 238, 255);
sf::Color const Constants::body_color = sf::Color(153, 255, 51, 255);
sf::Color const Constants::head_color = sf::Color(51, 204, 30, 255);

vector<pair<int, int>> const Constants::directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
//                                                              jos      stanga    sus    dreapta
vector<string> const Constants::ev_paths = {
    "files/apple.png",
    "files/watermelon.png",
    "files/pear.png",
    "files/key.png",
    "files/flower_red.png",
    "files/flower_yellow.png",
    "files/flower_purple.png",
    "files/flower_blue.png"};

pair<int, int> const Constants::NO_DISABLED = {-1, -1};
