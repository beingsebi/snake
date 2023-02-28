#include "game.hpp"

Game::Game() // constructor
{

    this->video_mode.width = 800;
    this->video_mode.height = 600;
    this->window = new sf::RenderWindow(this->video_mode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game() // destructor
{
    delete this->window;
}

// private functions:

void Game::poll_events()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        default:
            break;
        }
    }
}

// public functions:
bool Game::is_running() const
{
    return this->window->isOpen();
}

void Game::update()
{
    this->poll_events();
}

void Game::render()
{
    this->window->clear();

    // draw here

    this->window->display();
}