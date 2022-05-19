#include "Pushbutton.hpp"
#include "iostream"
#include "graphics.hpp"
#include "string"
using namespace genv;

Pushbutton::Pushbutton(Gamemaster * Parent,int X,int Y, int Sx, int Sy, std::string S): Widget(Parent,X,Y,Sx,Sy){
    s = S;
}

void Pushbutton::draw(){
    gout<<move_to(x,y)<<color(128,128,128)<<box(sx,sy)
    <<move_to(x+2,y+2)<<color(211,211,211)<<box(sx-4,sy-4);
    gout << color(0,0,0);
    gout <<move_to(x+sx/2 - gout.twidth(s)/2, y+sy/2-(gout.cascent()+gout.cdescent())/2)<<text(s);
}
/*int Pushbutton::renumb(){
    return numb;
}*/
void Pushbutton::handle(genv::event ev){
    if (s=="Start 2v2"){
        parent->ismenu=false;
    }
    if (s=="Back to menu"){
        parent->isend=false;
        parent->play1.clear();
        parent->play2.clear();
        parent->start_screen();
        parent->ismenu=true;
        for (int i=6; i<parent->w.size();i++){
            parent->w[i]->handle(ev);
        }
    }
}
