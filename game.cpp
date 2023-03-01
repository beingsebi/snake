#include "game.hpp"

Game::Game() // constructor
{
    this->video_mode.width = 800 + 2;
    this->video_mode.height = 600 + 2;
    this->window = new sf::RenderWindow(this->video_mode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(this->video_mode.getDesktopMode().width / 2 - 400, this->video_mode.getDesktopMode().height / 2 - 300));
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

void Game::draw_canvas(const vector<vector<Cell>> &m)
{
    for (const auto &i : m)
        for (const auto &j : i)
            this->window->draw(j.get_rect());
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
    this->draw_canvas(this->canvas.get_matrix());

    //
    this->window->display();
}