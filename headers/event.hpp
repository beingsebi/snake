#ifndef EVENT_H
#define EVENT_H
#include <string>
using std::pair;
using std::string;
class Event
{
protected:
    pair<int, int> pos;
    string path;
    int scale;

    virtual void actiune() = 0;
    Event(const pair<int, int> &, const string &, const int);

public:
    virtual ~Event() = default;
    Event() = default;
    pair<int, int> get_pos() const;
    string get_path() const;
    int get_scale() const;
};

class Fruit : public Event
{
    int to_add;
    void actiune() override{};

public:
    virtual ~Fruit() = default;
    Fruit() = default;
    Fruit(const pair<int, int> &, const string &, const int, const int);
};

class Flower : public Event
{
    static int count;
    int theme;
    void actiune() override{};
    void bonus(){};

public:
    virtual ~Flower() = default;
    Flower() = default;
    Flower(const pair<int, int> &, const string &, const int, const int);
};

class Key : public Event
{

public:
    virtual ~Key() = default;
    void actiune() override{};
    Key() = default;
    Key(const pair<int, int> &, const string &, const int);
};

#endif