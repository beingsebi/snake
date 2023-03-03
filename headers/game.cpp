#include "constants.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
using std::ifstream;

Game::Game() // constructor
{
    this->font.loadFromFile("files/Roboto.ttf");
    this->video_mode.width = 800 + 2;
    this->video_mode.height = 600 + 2 + 25;
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

void Game::draw_canvas()
{
    for (const auto &i : this->canvas.matrix)
        for (const auto &j : i)
            this->window->draw(j.rect);
}
string Game::get_high_score() const
{
    static string s;
    ifstream f("files/high_score.txt");
    f >> s;
    return s;
}

void Game::draw_snake()
{
    static sf::RectangleShape rect;
    rect.setSize(Constants::cell_size);
    rect.setOutlineThickness(0.f);
    rect.setFillColor(Constants::color6);
    rect.setPosition(static_cast<float>(1 + snake.positions[0].second * Constants::cell_size.y),
                     static_cast<float>(1 + snake.positions[0].first * Constants::cell_size.x));
    this->window->draw(rect);

    rect.setFillColor(Constants::color5);
    for (int i = 1; i < (int)this->snake.positions.size(); i++)
    {
        rect.setPosition(static_cast<float>(1 + snake.positions[i].second * Constants::cell_size.y),
                         static_cast<float>(1 + snake.positions[i].first * Constants::cell_size.x));
        this->window->draw(rect);
    }
}

void Game::draw_scores()
{
    this->text_score.setFont(this->font);
    this->text_score.setString("Score:  " + std::to_string(this->score));
    this->text_score.setCharacterSize(20);
    this->text_score.setFillColor(sf::Color::White);
    this->text_score.setPosition(40.f, 602.f);
    this->window->draw(this->text_score);

    this->text_high_score.setFont(this->font);
    this->text_high_score.setString("High score:  " + this->get_high_score());
    this->text_high_score.setCharacterSize(20);
    this->text_high_score.setFillColor(sf::Color::White);
    this->text_high_score.setPosition(625.f, 602.f);
    this->window->draw(this->text_high_score);
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
    this->draw_canvas();
    this->draw_snake();
    this->draw_scores();
    //
    this->window->display();
}