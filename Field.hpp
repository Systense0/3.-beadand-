#ifndef FIELD_HPP
#define FIELD_HPP
#include "graphics.hpp"
#include "Widgets.hpp"
#include "fstream"
struct RGB{
    int r,g,b;
};
void beolvas(std::ifstream &kep, std::vector<RGB> &v, int XX, int YY);

class Field: public Widget{
protected:
    std::string shape = "";
    std::vector<RGB> circle;
    std::vector<RGB> ex;
public:
    Field(Gamemaster * Parent,int X, int Y, int Sx, int Sy);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // FIELD_HPP
