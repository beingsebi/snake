#include "../headers/game.hpp"
#ifndef ecd
#define ecd Constants::Directions
#endif
using std::ifstream;
Game::Game() // constructor
{
    this->font.loadFromFile("files/Roboto.ttf");
    this->video_mode.width = 800 + 2;
    this->video_mode.height = 600 + 2 + 25;
    // height + border + text
    this->window = new sf::RenderWindow(this->video_mode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(this->video_mode.getDesktopMode().width / 2 - 400, this->video_mode.getDesktopMode().height / 2 - 300));
    this->window->setFramerateLimit(4);
}

Game::~Game() // destructor
{
    delete this->window;
}

// private functions:

void Game::reset()
{
    while (!this->moves.empty())
        this->moves.pop();
    game_over = 0;
    this->canvas.init();
    this->snake.init();
    score = 0;
}

void Game::poll_events()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:

            switch (this->ev.key.code)
            {
            case sf::Keyboard::Escape:
                this->reset();
                break;

            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                if (this->moves.size() < 2)
                {
                    if (this->moves.empty() && this->snake.get_direction() != 1 && this->snake.get_direction() != ecd::right)
                        this->moves.push(ecd::left);
                    else if (!this->moves.empty() && this->moves.back() != 1 && this->moves.back() != ecd::right)
                        this->moves.push(ecd::left);
                }
                break;

            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                if (this->moves.size() < 2)
                {
                    if (this->moves.empty() && this->snake.get_direction() != 2 && this->snake.get_direction() != ecd::down)
                        this->moves.push(ecd::up);
                    else if (!this->moves.empty() && this->moves.back() != 2 && this->moves.back() != ecd::down)
                        this->moves.push(ecd::up);
                }
                break;

            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                if (this->moves.size() < 2)
                {
                    if (this->moves.empty() && this->snake.get_direction() != 3 && this->snake.get_direction() != ecd::left)
                        this->moves.push(ecd::right);
                    else if (!this->moves.empty() && this->moves.back() != 3 && this->moves.back() != ecd::left)
                        this->moves.push(ecd::right);
                }
                break;

            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                if (this->moves.size() < 2)
                {
                    if (this->moves.empty() && this->snake.get_direction() != 0 && this->snake.get_direction() != ecd::up)
                        this->moves.push(ecd::down);
                    else if (!this->moves.empty() && this->moves.back() != 0 && this->moves.back() != ecd::up)
                        this->moves.push(ecd::down);
                }
                break;

            default:
                break;
            }

            break;

        default:
            break;
        }
    }
}

void Game::draw_canvas()
{
    for (const auto &i : this->canvas.get_matrix())
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
    rect.setFillColor(Constants::head_color);
    rect.setPosition(static_cast<float>(1 + snake[0].second * Constants::cell_size.y),
                     static_cast<float>(1 + snake[0].first * Constants::cell_size.x));
    this->window->draw(rect);

    rect.setFillColor(Constants::body_color);
    for (int i = 1; i < (int)this->snake.getp_size(); i++)
    {
        rect.setPosition(static_cast<float>(1 + snake[i].second * Constants::cell_size.y),
                         static_cast<float>(1 + snake[i].first * Constants::cell_size.x));
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
void Game::check_game_over()
{
    if (this->snake.is_outside())
    {
        this->game_over = 1;
        return;
    }
    if (canvas.is_disabled(this->snake[0]))
    {
        this->game_over = 1;
        return;
    }
    for (int i = 1; i < (int)this->snake.getp_size(); i++)
        if (this->snake[0] == this->snake[i])
        {
            this->game_over = 1;
            return;
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
    if (this->game_over)
        this->reset();
    this->snake.move();
    check_game_over();
    if (this->game_over)
        this->reset();
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
    this->update_snake();
}

void Game::update_snake()
{
    if (!this->moves.empty())
        this->snake.set_direction(this->moves.front()), this->moves.pop();
}
ostream &operator<<(ostream &os, const Game &game)
{
    os << game.canvas << '\n'
       << game.snake << '\n';
    os << "Score: " << game.score << '\n';
    return os;
}
