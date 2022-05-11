#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include "graphics.hpp"
#include "Gamemaster.hpp"

class Widget{
protected:
    int x, y, sx, sy;
    Gamemaster *parent;
public:
    Widget(Gamemaster * Parent, int X, int Y, int Sx, int Sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGETS_HPP_INCLUDED
