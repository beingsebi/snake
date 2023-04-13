#ifndef EVENT_H
#define EVENT_H
#include <string>

class event
{
public:
    int posx, posy, scale;
    std::string path;
    virtual void actiune() = 0;
};

class fruct : public event
{
    int to_add;
    void actiune() override{};
};

class floare : public event
{
public:
    static int count;
    int new_theme;
    void actiune() override{

    };
    void bonus(){

    };
};

class cheie : public event
{
    void actiune() override{};
};

#endif