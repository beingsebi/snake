#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "canvas.hpp"
using std::string;
using std::vector;

class Game
{
    sf::RenderWindow *window;
    sf::VideoMode video_mode;
    sf::Event ev;
    sf::Text text_score;
    sf::Text text_high_score;
    sf::Font font;
    Canvas canvas;
    int score = 0;
    void poll_events();
    string get_high_score() const;
    void draw_canvas(const vector<vector<Cell>> &);
    void draw_scores();

public:
    Game();
    ~Game();
    bool is_running() const;
    void update();
    void render();
};
#endif