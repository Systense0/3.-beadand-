#include "staticbox.hpp"
#include "graphics.hpp"
#include "iostream"
using namespace genv;

Staticbox::Staticbox(Gamemaster *Parent,int X, int Y, int Sx, int Sy, std::string S):Widget(Parent,X, Y, Sx, Sy){
    s = S;
}
void Staticbox::draw(){
    gout << move_to(x,y) << color(255,51,51) << box(sx,sy) << color(255,255,255) << move_to(x+2,y+2) << box(sx-4,sy-4);
    gout << font("LiberationSans-Regular.ttf",28) << move_to(x+sx/2 - gout.twidth(s)/2, y+sy/2-(gout.cascent()+gout.cdescent())/2) << color(0,0,0)<<  text(s);
}
void Staticbox::handle(genv::event ev){

}
