#ifndef STATICBOX_HPP_INCLUDED
#define STATICBOX_HPP_INCLUDED
#include "graphics.hpp"
#include "Widgets.hpp"

class Staticbox: public Widget{
protected:
    std::string s;
public:
    Staticbox(Gamemaster *Parent,int X, int Y, int Sx, int Sy, std::string S);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // STATICBOX_HPP_INCLUDED
