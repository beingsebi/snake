#include "../headers/event.hpp"

int Flower::count = 0;

Event::Event(const pair<int, int> &p, const string &pth, const int scl) : pos{p}, path{pth}, scale{scl} {}

Fruit::Fruit(const pair<int, int> &p, const string &pth, const int scl, const int td) : Event{p, pth, scl}, to_add{td} {}

Flower::Flower(const pair<int, int> &p, const string &pth, const int scl, const int thm) : Event{p, pth, scl}, theme{thm} {}

Key::Key(const pair<int, int> &p, const string &pth, const int scl) : Event{p, pth, scl} {}

pair<int, int> Event::get_pos() const { return this->pos; }
string Event::get_path() const { return this->path; }
int Event::get_scale() const { return this->scale; }
