#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED
#include "string"
#include "vector"

class Widget;
class Field;
struct Kord{
    int x,y;
};
class Gamemaster{
protected:
    int X,Y;
    std::vector<Widget*> w;
    friend class Pushbutton;
public:
    Gamemaster(int x,int y);
    bool witchplayer = false;
    std::vector<Kord*> play1;
    std::vector<Kord*> play2;
    void start_screen();
    void end_screen(int k );
    bool ismenu;
    bool isend=false;
    void is_five();
    void cclear();
    void register_widget(Widget* widget);
    void delete_last_widget();
    void event_loop();
};

#endif // GAMEMASTER_HPP_INCLUDED
