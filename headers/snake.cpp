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

void Snake::move()
{
    for (int i = this->positions.size() - 1; i >= 1; i--)
        this->positions[i] = this->positions[i - 1];

    this->positions.front().first += Constants::directions[this->direction].first;
    this->positions.front().second += Constants::directions[this->direction].second;
}

ostream &operator<<(ostream &os, const Snake &snake)
{
    os << "Snake head at line " << snake.positions.front().first << " and column " << snake.positions.front().second << '\n';
    os << "Snake body: ";
    for (int i = 1; i < (int)snake.positions.size(); i++)
        os << "(" << snake.positions.at(i).first << "," << snake.positions.at(i).second << ")  ";
    os << "\nSnake goes ";
    if (snake.direction == 0)
        os << "down";
    if (snake.direction == 1)
        os << "left";
    if (snake.direction == 2)
        os << "up";
    if (snake.direction == 3)
        os << "right";
    os << '\n';
    return os;
}
