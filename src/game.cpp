#include "../headers/game.hpp"
#ifndef ecd
#define ecd Constants::Directions
#endif
using std::ifstream;
using std::make_unique;
using std::mt19937;

Game::Game()
{
    this->font.loadFromFile("files/Roboto.ttf");
    this->video_mode.width = 800 + 2;
    this->video_mode.height = 600 + 2 + 25; // height + border + text
    this->window = new sf::RenderWindow(this->video_mode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(this->video_mode.getDesktopMode().width / 2 - 400, this->video_mode.getDesktopMode().height / 2 - 300));
    this->window->setFramerateLimit(4);
    this->init_ev();
}

void Game::init_ev()
{
    static int p_k = 1, p_fl = 3, p_fr = 4;
    if (this->canvas.getr_disabled() == Constants::NO_DISABLED)
        p_k = 0;
    vector<int> vxr;
    static mt19937 mt(time(nullptr));
    static int guess, td;
    float scl;
    static pair<int, int> pz, off;
    static string pth;

    pz = this->canvas.getr_enabled();

    for (int i = 1; i <= p_k; i++)
        vxr.push_back(1);
    for (int i = 1; i <= p_fl; i++)
        vxr.push_back(2);
    for (int i = 1; i <= p_fr; i++)
        vxr.push_back(3);

    guess = vxr[mt() % vxr.size()];
    guess = 1;
    if (guess == 1)
    {
        off = {9, 0};
        pth = Constants::ev_paths[Constants::key];
        scl = 1.5f;
        this->s_ev = make_unique<Key>(pz, off, pth, scl);
    }
    else if (guess == 2)
    {
        guess = mt() % 3;
        pth = Constants::ev_paths[4 + guess];
        scl = 1.6f;
        off = {2, 4};
        this->s_ev = make_unique<Flower>(pz, off, pth, scl, 1);
    }
    else /*if (guess <= p_fr)*/
    {
        guess = mt() % 3;
        switch (guess)
        {
        case 0:
            off = {6, 5};
            td = 1;
            break;
        case 1:
            off = {10, -2};
            td = 3;
            break;
        case 2:
            off = {2, 4};
            td = 2;
            break;
        }
        pth = Constants::ev_paths[guess];
        scl = 1.5f;
        this->s_ev = make_unique<Fruit>(pz, off, pth, scl, td);
    }
}

Game::~Game()
{
    delete this->window;
}

void Game::reset()
{
    while (!this->moves.empty())
        this->moves.pop();
    game_over = 0;
    this->canvas.init();
    this->snake.init();
    this->init_ev();
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
            this->window->draw(j.get_rect());
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

void Game::draw_event()
{
    static pair<int, int> ax1, ax2;
    sf::Sprite sprite;
    sf::Texture texture;
    if (!texture.loadFromFile(this->s_ev.get()->get_path()))
    {
    }
    sprite.setTexture(texture);
    sprite.setScale(this->s_ev.get()->get_scale(), this->s_ev.get()->get_scale());
    ax1 = this->s_ev.get()->get_pos();
    ax2 = this->s_ev.get()->get_offset();
    sprite.setPosition(ax2.second + ax1.second * Constants::cell_size.y,
                       ax2.first + ax1.first * Constants ::cell_size.x);
    this->window->draw(sprite);
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
    check_event();
    if (this->game_over)
        this->reset();
}

void Game::render()
{
    this->window->clear();

    // draw here
    this->draw_canvas();
    this->draw_event();
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

void Game::check_event()
{
    if (this->s_ev.get()->get_pos() != this->snake[0])
        return;

    this->s_ev.get()->actiune(this->canvas);
    if (auto *c = dynamic_cast<Flower *>(this->s_ev.get()))
        c->bonus();

    this->init_ev();
}
