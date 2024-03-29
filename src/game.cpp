#include "../headers/game.hpp"
#ifndef ecd
#define ecd Constants::Directions
#endif
using std::ifstream;
using std::make_unique;
using std::mt19937;

template <typename T>
Game<T> &Game<T>::get_game()
{
    static Game<T> game;
    return game;
}

template <typename T>
Game<T>::Game()
{
    if (!this->font.loadFromFile("files/Roboto.ttf"))
    {
        throw file_error("Unable to load font");
    }
    this->video_mode.width = 800 + 2;
    this->video_mode.height = 600 + 2 + 25; // height + border + text
    this->window = new sf::RenderWindow(this->video_mode, "Snake game", sf::Style::Titlebar | sf::Style::Close);
    auto image = sf::Image{};
    if (!image.loadFromFile("files/logo.png"))
    {
        throw file_error("Unable to load logo");
    }
    else
        this->window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    this->window->setPosition(sf::Vector2i(this->video_mode.getDesktopMode().width / 2 - 400, this->video_mode.getDesktopMode().height / 2 - 300));
    this->window->setFramerateLimit(3);
    this->init_ev();
}

template <typename T>
void Game<T>::init_ev()
{
    this->s_ev.reset();
    static int p_k = Constants::prob_key,
               p_fl = Constants::prob_flower,
               p_fr = Constants::prob_fruit,
               p_egg = Constants::prob_egg; // probabilitiesssss
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
    for (int i = 1; i <= p_egg; i++)
        vxr.push_back(4);
    guess = vxr[mt() % vxr.size()];
    if (guess == 1)
    {
        off = {9, 0};
        pth = Constants::ev_paths[Constants::key];
        scl = 1.5f;
        this->s_ev = make_unique<Key<T>>(this, pz, off, pth, scl);
    }
    else if (guess == 2)
    {
        do
        {
            guess = mt() % 4;
        } while (static_cast<Constants::Themes>(guess) == this->theme);
        pth = Constants::ev_paths[4 + guess];
        scl = 1.6f;
        off = {2, 4};
        this->s_ev = make_unique<Flower<T>>(this, pz, off, pth, scl, static_cast<Constants::Themes>(guess));
    }
    else if (guess == 3)
    {
        if (this->theme == Constants::Themes::red)
            guess = (1 + (mt() % 2));
        else
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
        this->s_ev = make_unique<Fruit<T>>(this, pz, off, pth, scl, td);
    }
    else if (guess == 4)
    {
        pth = Constants::ev_paths[8];
        scl = 1.6f;
        off = {0, 0};
        td = -5;
        this->s_ev = make_unique<Vegetable<T>>(this, pz, off, pth, scl, td);
    }
}

template <typename T>
Game<T>::~Game()
{
    delete this->window;
}

template <typename T>
void Game<T>::reset()
{
    while (!this->moves.empty())
        this->moves.pop();
    game_over = 0;
    this->canvas.init();
    this->snake.init();
    this->theme = Constants::Themes::blue; //! the order!!
    this->init_ev();
    score = 0;
    this->reset_count();
}

template <typename T>
void Game<T>::poll_events()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyReleased:
            if (this->ev.key.code == sf::Keyboard::Space)
                this->window->setFramerateLimit(3);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->window->setFramerateLimit(7);
}

template <typename T>
void Game<T>::draw_canvas()
{
    static sf::RectangleShape rect;
    for (const auto &i : this->canvas.get_matrix())
        for (const auto &j : i)
        {
            rect = j.get_rect();
            if (j.is_enabled())
                rect.setFillColor(Constants::cell_color[theme]);
            else
                rect.setFillColor(Constants::disabled_color[theme]);
            rect.setOutlineColor(Constants::border_color[theme]);
            this->window->draw(rect);
        }
}

template <typename T>
void Game<T>::increment_count()
{
    this->bonus_count++;
}

template <typename T>
void Game<T>::reset_count()
{
    this->bonus_count = 0;
}

template <typename T>
int Game<T>::get_count() const
{
    return this->bonus_count;
}

template <typename T>
string Game<T>::get_high_score() const
{
    static string s;
    ifstream f(Constants::HIGH_SCORE_PATH);
    f >> s;
    if (s.empty())
        s = "0";
    int hs = 0;
    for (const auto &i : s)
        if (!isdigit(i))
            throw score_error("Invalid score.");
        else
            hs = hs * 10 + i - '0';
    if (hs > 10000)
        throw score_error("Invalid score.");
    return s;
}

template <typename T>
void Game<T>::draw_snake()
{
    static sf::RectangleShape rect;
    rect.setSize(Constants::cell_size);
    rect.setOutlineThickness(0.f);
    rect.setFillColor(Constants::head_color[theme]);
    rect.setPosition(static_cast<float>(1 + snake[0].second * Constants::cell_size.y),
                     static_cast<float>(1 + snake[0].first * Constants::cell_size.x));
    this->window->draw(rect);

    rect.setFillColor(Constants::body_color[theme]);
    for (int i = 1; i < (int)this->snake.getp_size(); i++)
    {
        rect.setPosition(static_cast<float>(1 + snake[i].second * Constants::cell_size.y),
                         static_cast<float>(1 + snake[i].first * Constants::cell_size.x));
        this->window->draw(rect);
    }
}

template <typename T>
void Game<T>::draw_event()
{
    static pair<int, int> ax1, ax2;
    sf::Sprite sprite;
    sf::Texture texture;
    if (!texture.loadFromFile(this->s_ev.get()->get_path()))
    {
        throw file_error("Unable to load event image.");
    }
    sprite.setTexture(texture);
    sprite.setScale(this->s_ev.get()->get_scale(), this->s_ev.get()->get_scale());
    ax1 = this->s_ev.get()->get_pos();
    ax2 = this->s_ev.get()->get_offset();
    sprite.setPosition(ax2.second + ax1.second * Constants::cell_size.y,
                       ax2.first + ax1.first * Constants ::cell_size.x);
    this->window->draw(sprite);
}

template <typename T>
void Game<T>::draw_scores()
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

template <typename T>
void Game<T>::check_game_over()
{
    if (this->snake.is_outside() || canvas.is_disabled(this->snake[0]))
    {
        this->game_over = 1;
        check_high_score();
        return;
    }
    for (int i = 1; i < (int)this->snake.getp_size(); i++)
        if (this->snake[0] == this->snake[i])
        {
            this->game_over = 1;
            check_high_score();
            return;
        }
}

template <typename T>
bool Game<T>::is_running() const
{
    return this->window->isOpen();
}

template <typename T>
void Game<T>::update()
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

template <typename T>
void Game<T>::render()
{
    this->window->clear();

    // draw here
    this->draw_canvas();
    this->draw_event(); // might throw file_error
    this->draw_snake();
    this->draw_scores(); // might throw score_error
    //
    this->window->display();
    this->update_snake();
}

template <typename T>
void Game<T>::update_snake()
{
    if (!this->moves.empty())
        this->snake.set_direction(this->moves.front()), this->moves.pop();
}

template <typename T>
ostream &operator<<(ostream &os, const Game<T> &game)
{
    os << game.canvas << '\n'
       << game.snake << '\n';
    os << "Score: " << game.score << '\n';
    return os;
}

template <typename T>
void Game<T>::check_event()
{
    if (this->s_ev.get()->get_pos() != this->snake[0])
        return;

    this->s_ev.get()->actiune();
    if (auto *c = dynamic_cast<Flower<T> *>(this->s_ev.get()))
        c->bonus();

    this->init_ev();
}

template <typename T>
Canvas &Game<T>::get_canvas()
{
    return canvas;
}

template <typename T>
void Game<T>::set_theme(const Constants::Themes thm)
{
    this->theme = thm;
}

template <typename T>
void Game<T>::add_grow(int gr)
{
    this->snake.add_grow(gr);
}

template <typename T>
void Game<T>::add_score(T s)
{
    this->score += s;
}

template <typename T>
void Game<T>::check_high_score()
{
    static int hs;
    hs = 0;
    for (const char &c : get_high_score())
        hs = hs * 10 + c - '0';
    if (this->score > hs)
    {
        std::ofstream g(Constants::HIGH_SCORE_PATH);
        g << this->score << std::endl;
    }
}
