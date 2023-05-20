#include "../headers/event.hpp"
#include "../headers/game.hpp"

template <typename T>
Event<T>::Event(Game<T> *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : pg{g}, pos{p}, offset{off}, path{pth}, scale{scl} {}

template <typename T>
Fruit<T>::Fruit(Game<T> *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int td) : Event<T>{g, p, off, pth, scl}, to_add{td} {}

template <typename T>
Flower<T>::Flower(Game<T> *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const Constants::Themes thm) : Event<T>{g, p, off, pth, scl}, theme{thm} {}

template <typename T>
Key<T>::Key(Game<T> *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : Event<T>{g, p, off, pth, scl} {}

template <typename T>
pair<int, int> Event<T>::get_pos() const { return this->pos; }

template <typename T>
pair<int, int> Event<T>::get_offset() const { return this->offset; }

template <typename T>
string Event<T>::get_path() const { return this->path; }

template <typename T>
float Event<T>::get_scale() const { return this->scale; }

template <typename T>
void Flower<T>::actiune()
{
    this->pg->set_theme(this->theme);
}

template <typename T>
void Fruit<T>::actiune()
{
    this->pg->add_grow(this->to_add);
    this->pg->add_score(this->to_add * 5);
}

template <typename T>
void Key<T>::actiune()
{
    this->pg->get_canvas().enable_rcell();
    this->pg->add_score(Constants::key_score);
}

template <typename T>
void Flower<T>::bonus()
{
    this->pg->increment_count();
    if (!(this->pg->get_count() % Constants::bonus_mod))
        this->pg->add_score((T)Constants::bonus_score / 4),
            this->pg->add_grow(1);
}

template <typename T>
void Flower<T>::reset_count()
{
    this->pg->reset_count();
}

template <typename T>
Vegetable<T>::Vegetable(Game<T> *g, const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int td) : Event<T>{g, p, off, pth, scl}, penalty{td} {}

template <typename T>
void Vegetable<T>::actiune()
{
    this->pg->add_score(this->penalty);
}
