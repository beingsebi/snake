#ifndef EVENT_H
#define EVENT_H
#include "cell.hpp"
#include "canvas.hpp"
#include <string>
#include <fstream>
using std::pair;
using std::string;

template <typename T>
class Game;

template <typename T>
class Event
{
protected:
    Game<T> *pg;
    pair<int, int> pos, offset;
    string path;
    float scale;
    Event(Game<T> *, const pair<int, int> &, const pair<int, int> &, const string &, const float);

public:
    virtual ~Event() = default;
    virtual void actiune() = 0;
    Event() = default;
    pair<int, int> get_pos() const;
    pair<int, int> get_offset() const;
    string get_path() const;
    float get_scale() const;
};

template <typename T>
class Fruit : public Event<T>
{
    int to_add;

public:
    void actiune() override;
    virtual ~Fruit() = default;
    Fruit() = default;
    Fruit(Game<T> *, const pair<int, int> &, const pair<int, int> &, const string &, const float, const int);
};

template <typename T>
class Flower : public Event<T>
{
    Constants::Themes theme;

public:
    void actiune() override;
    void bonus();
    virtual ~Flower() = default;
    void reset_count();
    Flower() = default;
    Flower(Game<T> *, const pair<int, int> &, const pair<int, int> &, const string &, const float, const Constants::Themes);
};

template <typename T>
class Key : public Event<T>
{

public:
    virtual ~Key() = default;
    void actiune() override;
    Key() = default;
    Key(Game<T> *, const pair<int, int> &, const pair<int, int> &, const string &, const float);
};

template <typename T>
class Vegetable : public Event<T>
{
    int penalty;

public:
    void actiune() override;
    virtual ~Vegetable() = default;
    Vegetable() = default;
    Vegetable(Game<T> *, const pair<int, int> &, const pair<int, int> &, const string &, const float, const int);
};
#endif