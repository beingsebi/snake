#include "../headers/event.hpp"
#include "../headers/game.hpp"

int Flower::count = 0;

Event::Event(Game *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : pg{g}, pos{p}, offset{off}, path{pth}, scale{scl} {}

Fruit::Fruit(Game *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int td) : Event{g, p, off, pth, scl}, to_add{td} {}

Flower::Flower(Game *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const Constants::Themes thm) : Event{g, p, off, pth, scl}, theme{thm} {}

Key::Key(Game *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : Event{g, p, off, pth, scl} {}

pair<int, int> Event::get_pos() const { return this->pos; }
pair<int, int> Event::get_offset() const { return this->offset; }
string Event::get_path() const { return this->path; }
float Event::get_scale() const { return this->scale; }

void Flower::actiune()
{
    this->pg->set_theme(this->theme);
}

void Fruit::actiune()
{
    this->pg->add_grow(this->to_add);
    this->pg->add_score(this->to_add * 5);
}

void Key::actiune()
{
    this->pg->get_canvas().enable_rcell();
    this->pg->add_score(Constants::key_score);
}

void Flower::bonus()
{
    count = (count + 1) % 5;
    if (!count)
        this->pg->add_score(Constants::bonus_score),
            this->pg->add_grow(1);
}

void Flower::reset_count()
{
    count = 0;
}

Vegetable::Vegetable(Game *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int td) : Event{g, p, off, pth, scl}, penalty{td} {}

void Vegetable::actiune()
{
    this->pg->add_score(this->penalty);
}
