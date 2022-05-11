#include "Widgets.hpp"
#include "graphics.hpp"
#include "iostream"

using namespace genv;

Widget::Widget(Gamemaster * Parent, int X, int Y, int Sx, int Sy):parent(Parent),x(X),y(Y),sx(Sx),sy(Sy){
    parent->register_widget(this);
}
bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>x && mouse_x<x+sx && mouse_y>y && mouse_y<y+sy;
}
