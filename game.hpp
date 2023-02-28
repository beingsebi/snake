#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow *window;
    sf::VideoMode video_mode;
    sf::Event ev;

    void poll_events();

public:
    Game();
    ~Game();
    bool is_running() const;
    void update();
    void render();
};
#endif