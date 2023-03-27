#include "../headers/constants.hpp"

sf::Vector2f const Constants::cell_size = sf::Vector2f(40.f, 40.f);

sf::Color const Constants::cell_color = sf::Color(34, 40, 49, 255);
// sf::Color const Constants::color2 = sf::Color(57, 62, 70, 255);
sf::Color const Constants::border_color = sf::Color(0, 173, 181, 255);
sf::Color const Constants::disabled_color = sf::Color(238, 238, 238, 255);
sf::Color const Constants::body_color = sf::Color(153, 255, 51, 255);
sf::Color const Constants::head_color = sf::Color(51, 204, 30, 255);

int const Constants::lines = 15;
int const Constants::columns = 20;
std::vector<std::pair<int, int>> const Constants::directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
//                                                              jos      stanga    sus    dreapta