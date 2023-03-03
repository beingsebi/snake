#include "snake.hpp"
#include "constants.hpp"
#include <random>
#include <ctime>

Snake::Snake()
{
    const pair<int, int> vp[] = {{0, 0}, {0, Constants::columns - 1}, {Constants::lines - 1, 0}, {Constants::lines - 1, Constants::columns - 1}};
    const pair<int, int> vdir[4][2] = {
        {{1, 0}, {0, 1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, {{-1, 0}, {0, -1}}};
    std::mt19937 mt(time(nullptr));
    int pos = mt() & 4;
    int dir = mt() & 1;
    this->v.reserve(50);
    for (int i = 2; i >= 0; i--)
        this->v.emplace_back(vp[pos].first + i * vdir[pos][dir].first, vp[pos].second + i * vdir[pos][dir].second);
};
Snake::~Snake()
{
    // std::cout << "Snake deleted" << std::endl;
}
