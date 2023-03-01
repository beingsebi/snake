#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "canvas.hpp"
using std::vector;

class Game
{
    sf::RenderWindow *window;
    sf::VideoMode video_mode;
    sf::Event ev;
    Canvas canvas;
    void poll_events();
    void draw_canvas(const vector<vector<Cell>> &);

public:
    Game();
    ~Game();
    bool is_running() const;
    void update();
    void render();
};
#endif