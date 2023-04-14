#ifndef EVENT_H
#define EVENT_H
#include "cell.hpp"
#include "canvas.hpp"
#include <string>
#include <iostream>
using std::pair;
using std::string;
class Event
{
protected:
    pair<int, int> pos, offset;
    string path;
    float scale;
    Event(const pair<int, int> &, const pair<int, int> &, const string &, const float);

public:
    virtual ~Event() = default;
    virtual void actiune(Canvas &) = 0;
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
    void actiune(Canvas &) override;
    virtual ~Fruit() = default;
    Fruit() = default;
    Fruit(const pair<int, int> &, const pair<int, int> &, const string &, const float, const int);
};

class Flower : public Event
{
    static int count;
    int theme;

public:
    void actiune(Canvas &) override;
    void bonus();
    virtual ~Flower() = default;
    Flower() = default;
    Flower(const pair<int, int> &, const pair<int, int> &, const string &, const float, const int);
};

class Key : public Event
{

public:
    virtual ~Key() = default;
    void actiune(Canvas &) override;
    Key() = default;
    Key(const pair<int, int> &, const pair<int, int> &, const string &, const float);
};

#endif