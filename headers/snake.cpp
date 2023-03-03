#include "snake.hpp"
#include "constants.hpp"
#include <random>
#include <ctime>

#include <iostream>
Snake::Snake()
{

    std::mt19937 mt(time(nullptr));
    switch (mt() % 8)
    {
    case 0:
        positions = {{0, 2}, {0, 1}, {0, 0}};
        break;
    case 1:
        positions = {{2, 0}, {1, 0}, {0, 0}};
        break;
    case 2:
        positions = {{2, Constants::columns - 1}, {1, Constants::columns - 1}, {0, Constants::columns - 1}};
        break;
    case 3:
        positions = {{0, Constants::columns - 3}, {0, Constants::columns - 2}, {0, Constants::columns - 1}};
        break;
    case 4:
        positions = {{Constants::lines - 3, 0}, {Constants::lines - 2, 0}, {Constants::lines - 1, 0}};
        break;
    case 5:
        positions = {{Constants::lines - 1, 2}, {Constants::lines - 1, 1}, {Constants::lines - 1, 0}};
        break;
    case 6:
        positions = {{Constants::lines - 1, Constants::columns - 3}, {Constants::lines - 1, Constants::columns - 2}, {Constants::lines - 1, Constants::columns - 1}};
        break;
    case 7:
        positions = {{Constants::lines - 3, Constants::columns - 1}, {Constants::lines - 2, Constants::columns - 1}, {Constants::lines - 1, Constants::columns - 1}};
        break;
    }
    for (auto i : positions)
        std::cout << i.first << " " << i.second << std::endl;
};
Snake::~Snake()
{
    // std::cout << "Snake deleted" << std::endl;
}
