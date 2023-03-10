#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <ostream>
#include "canvas.hpp"
#include "snake.hpp"
using std::ostream;
using std::queue;
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
    Snake snake;
    int score = 0;
    bool game_over = 0;
    queue<int> moves;

    void poll_events();
    string get_high_score() const;
    void draw_canvas();
    void draw_snake();
    void draw_scores();
    void reset();
    void check_game_over();

    Game(const Game &) = delete;
    Game operator=(const Game &) = delete;

public:
    Game();
    ~Game();
    bool is_running() const;
    void update();
    void render();
    friend ostream &operator<<(ostream &, const Game &);
};
#endif