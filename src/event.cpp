#include "../headers/event.hpp"

int Flower::count = 0;

Event::Event(const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : pos{p}, offset{off}, path{pth}, scale{scl} {}

Fruit::Fruit(const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int td) : Event{p, off, pth, scl}, to_add{td} {}

Flower::Flower(const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl, const int thm) : Event{p, off, pth, scl}, theme{thm} {}

Key::Key(const pair<int, int> &p, const pair<int, int> &off, const string &pth, const float scl) : Event{p, off, pth, scl} {}

pair<int, int> Event::get_pos() const { return this->pos; }
pair<int, int> Event::get_offset() const { return this->offset; }
string Event::get_path() const { return this->path; }
float Event::get_scale() const { return this->scale; }
