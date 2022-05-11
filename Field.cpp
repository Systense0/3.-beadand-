#include "Field.hpp"
#include "graphics.hpp"
#include "fstream"
#include "iostream"
using namespace genv;
void beolvas(std::ifstream &kep, std::vector<RGB> &v, int XX, int YY){
    RGB uj;
    for(int i=0; i<YY; i++){
        for(int j=0; j<XX; j++){
            kep >> uj.r >> std::ws >> uj.g >> std::ws >> uj.b >> std::ws;
            v.push_back(uj);
        }
    }
}
Field::Field(Gamemaster * Parent,int X,int Y, int Sx, int Sy): Widget(Parent,X,Y,Sx,Sy){
    std::ifstream kep1;
    kep1.open("Circle.bmp.kep");
    int XX,YY;
    kep1 >> XX >> std::ws >> YY >> std::ws;
    std::vector<RGB> u;
    beolvas(kep1,u,XX,YY);
    kep1.close();
    circle = u;

    std::ifstream kep2;
    kep2.open("Ex.bmp.kep");
    kep2 >> XX >> std::ws >> YY >> std::ws;
    std::vector<RGB> v;
    beolvas(kep2,v,XX,YY);
    kep2.close();
    ex = v;
}

void Field::draw(){
    gout<<move_to(x,y)<<color(0,0,128)<<box(sx,sy)
    <<move_to(x+2,y+2)<<color(0,0,0)<<box(sx-4,sy-4);
    gout << color(0,0,0);
    if (shape == "x"){
        gout << move_to(x+2,y+2);
        int k =0;
        for(int i=0; i<sy-4; i++){
            for(int j=0; j<sx-4; j++){
                gout << move_to(x+2+j,y+2+i) << color(ex[k].r, ex[k].g, ex[k].b) << dot;
                k++;
            }
        }
    }
    if (shape == "o"){
        gout << move_to(x+2,y+2);
        int k =0;
        for(int i=0; i<sy-4; i++){
            for(int j=0; j<sx-4; j++){
                gout << move_to(x+2+j,y+2+i) << color(circle[k].r, circle[k].g, circle[k].b) << dot;
                k++;
            }
        }
    }
}

void Field::handle(genv::event ev){
    if (parent->ismenu){
        shape = "";
    }
    else if (shape==""){
        Kord *k = new Kord;
        k->x=x;
        k->y=y;
        if (parent->witchplayer){
            shape="x";
            parent->play2.push_back(k);
        }
        else{
            shape = "o";
            parent->play1.push_back(k);
        }
    }
    else{
        if (parent->witchplayer){
            parent->witchplayer=false;
        }
        else{
            parent->witchplayer=true;
        }
    }
}
