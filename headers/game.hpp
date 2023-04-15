#ifndef GAME_H
#define GAME_H

#include "constants.hpp"
#include "canvas.hpp"
#include "snake.hpp"
#include "event.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <queue>
#include <ostream>
#include <memory>
#include <random>

using std::ostream;
using std::queue;
using std::string;
using std::unique_ptr;
using std::vector;

class Event;
class Game
{
    sf::RenderWindow *window;
    sf::VideoMode video_mode;
    sf::Event ev;
    sf::Text text_score;
    sf::Text text_high_score;
    sf::Font font;
    Canvas canvas;
    Snake snake;
    unique_ptr<Event> s_ev;
    int score = 0;
    Constants::Themes theme = Constants::Themes::blue;
    bool game_over = 0;
    queue<int> moves;

    void poll_events();
    string get_high_score() const;
    void init_ev();
    void draw_canvas();
    void draw_snake();
    void draw_event();
    void draw_scores();
    void reset();
    void check_game_over();
    void update_snake();
    void check_event();
    void check_high_score();
    Game(const Game &) = delete;
    Game operator=(const Game &) = delete;

public:
    Game();
    ~Game();
    bool is_running() const;
    void update();
    void render();
    void set_theme(const Constants::Themes);
    void add_grow(const int &);
    void add_score(const int &);
    Canvas &get_canvas();
    friend ostream &operator<<(ostream &, const Game &);
};
#endif