#include "snake.hpp"
#include "constants.hpp"
#include <random>
#include <ctime>

Snake::Snake()
{
    std::mt19937 mt(time(nullptr));
    switch (mt() % 8)
    {
    case 0:
        this->positions = {{0, 2}, {0, 1}, {0, 0}};
        this->direction = 3;
        break;
    case 1:
        this->positions = {{2, 0}, {1, 0}, {0, 0}};
        this->direction = 0;
        break;
    case 2:
        this->positions = {{2, Constants::columns - 1}, {1, Constants::columns - 1}, {0, Constants::columns - 1}};
        this->direction = 0;
        break;
    case 3:
        this->positions = {{0, Constants::columns - 3}, {0, Constants::columns - 2}, {0, Constants::columns - 1}};
        this->direction = 1;
        break;
    case 4:
        this->positions = {{Constants::lines - 3, 0}, {Constants::lines - 2, 0}, {Constants::lines - 1, 0}};
        this->direction = 2;
        break;
    case 5:
        this->positions = {{Constants::lines - 1, 2}, {Constants::lines - 1, 1}, {Constants::lines - 1, 0}};
        this->direction = 3;
        break;
    case 6:
        this->positions = {{Constants::lines - 1, Constants::columns - 3}, {Constants::lines - 1, Constants::columns - 2}, {Constants::lines - 1, Constants::columns - 1}};
        this->direction = 1;
        break;
    case 7:
        this->positions = {{Constants::lines - 3, Constants::columns - 1}, {Constants::lines - 2, Constants::columns - 1}, {Constants::lines - 1, Constants::columns - 1}};
        this->direction = 2;
        break;
    }
};
Snake::~Snake()
{
    // std::cout << "Snake deleted" << std::endl;
}

void Snake::reset()
{
    // *this = Snake();
    this->~Snake();
    new (this) Snake();
}