#include "../headers/constants.hpp"

int const Constants::lines = 15;
int const Constants::columns = 20;
int const Constants::bonus_score = 82;
int const Constants::bonus_mod = 5;
int const Constants::key_score = 10;

int const Constants::prob_key = 4;
int const Constants::prob_flower = 6;
int const Constants::prob_fruit = 12;
int const Constants::prob_egg = 0;
string const Constants::HIGH_SCORE_PATH = "files/hs";
sf::Vector2f const Constants::cell_size = sf::Vector2f(40.f, 40.f);

sf::Color const Constants::cell_color[] = {
    sf::Color(34, 40, 49, 255),
    sf::Color(252, 245, 199, 255),
    sf::Color(239, 80, 80, 255),
    sf::Color(236, 176, 225, 255),
};
sf::Color const Constants::border_color[] = {
    sf::Color(0, 173, 181, 255),
    sf::Color(231, 216, 132, 255),
    sf::Color(192, 0, 50, 255),
    sf::Color(140, 33, 85, 255),
};
sf::Color const Constants::disabled_color[] = {
    sf::Color(238, 238, 238, 255),
    sf::Color(160, 206, 217, 255),
    sf::Color(43, 45, 66, 255),
    sf::Color(124, 124, 124, 255),
};
sf::Color const Constants::body_color[] = {
    sf::Color(153, 255, 51, 255),
    sf::Color(235, 185, 223, 255),
    sf::Color(237, 242, 244, 255),
    sf::Color(215, 219, 7, 255),
};
sf::Color const Constants::head_color[] = {
    sf::Color(51, 204, 30, 255),
    sf::Color(217, 145, 186, 255),
    sf::Color(141, 153, 174, 255),
    sf::Color(176, 226, 152, 255),
};

vector<pair<int, int>> const Constants::directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
//                                                              jos      stanga    sus    dreapta
vector<string> const Constants::ev_paths = {
    "files/apple.png",
    "files/watermelon.png",
    "files/pear.png",
    "files/key.png",
    "files/flower_blue.png",
    "files/flower_yellow.png",
    "files/flower_red.png",
    "files/flower_purple.png",
    "files/eggplant.png"};

pair<int, int> const Constants::NO_DISABLED = {-1, -1};
