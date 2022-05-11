#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED
#include "graphics.hpp"
#include "Widgets.hpp"

class Pushbutton: public Widget{
protected:
    std::string s;
public:
    Pushbutton(Gamemaster* Parent,int X, int Y, int Sx, int Sy, std::string S);
    virtual void draw();
    ///virtual int renumb();
    virtual void handle(genv::event ev);
};


#endif // PUSHBUTTON_HPP_INCLUDED
