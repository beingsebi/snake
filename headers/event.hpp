#ifndef EVENT_H
#define EVENT_H
#include "cell.hpp"
#include "canvas.hpp"
#include <string>
#include <fstream>
using std::pair;
using std::string;

class Game;
class Event
{
protected:
    Game *pg;
    pair<int, int> pos, offset;
    string path;
    float scale;
    Event(Game *, const pair<int, int> &, const pair<int, int> &, const string &, const float);

public:
    virtual ~Event() = default;
    virtual void actiune() = 0;
    Event() = default;
    pair<int, int> get_pos() const;
    pair<int, int> get_offset() const;
    string get_path() const;
    float get_scale() const;
};

class Fruit : public Event
{
    int to_add;

public:
    void actiune() override;
    virtual ~Fruit() = default;
    Fruit() = default;
    Fruit(Game *, const pair<int, int> &, const pair<int, int> &, const string &, const float, const int);
};

class Flower : public Event
{
    static int count;
    Constants::Themes theme;

public:
    void actiune() override;
    void bonus();
    virtual ~Flower() = default;
    static void reset_count();
    Flower() = default;
    Flower(Game *, const pair<int, int> &, const pair<int, int> &, const string &, const float, const Constants::Themes);
};

class Key : public Event
{

public:
    virtual ~Key() = default;
    void actiune() override;
    Key() = default;
    Key(Game *, const pair<int, int> &, const pair<int, int> &, const string &, const float);
};

#endif