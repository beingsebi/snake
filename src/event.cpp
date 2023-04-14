#include "../headers/event.hpp"

int Flower::count = 0;

Event::Event(const pair<int, int> &p, const string &pth, const float scl) : pos{p}, path{pth}, scale{scl} {}

Fruit::Fruit(const pair<int, int> &p, const string &pth, const float scl, const int td) : Event{p, pth, scl}, to_add{td} {}

Flower::Flower(const pair<int, int> &p, const string &pth, const float scl, const int thm) : Event{p, pth, scl}, theme{thm} {}

Key::Key(const pair<int, int> &p, const string &pth, const float scl) : Event{p, pth, scl} {}

pair<int, int> Event::get_pos() const { return this->pos; }
string Event::get_path() const { return this->path; }
float Event::get_scale() const { return this->scale; }
