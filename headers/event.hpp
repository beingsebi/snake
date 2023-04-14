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
    virtual ~Event() = default;
};

class Fruit : public Event
{
    int to_add;
    void actiune() override{};
    virtual ~Fruit() = default;

public:
    Fruit(const pair<int, int> &, const string &, const int, const int);
};

class Flower : public Event
{
    static int count;
    int theme;
    void actiune() override;
    void bonus();
    virtual ~Flower() = default;

public:
    Flower(const pair<int, int> &, const string &, const int, const int);
};

class Key : public Event
{
    void actiune() override{};
    virtual ~Key() = default;

public:
    Key(const pair<int, int> &, const string &, const int);
};

#endif