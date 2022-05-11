#include "Gamemaster.hpp"
#include "Field.hpp"
#include "Widgets.hpp"
#include "graphics.hpp"
#include "iostream"
#include <time.h>

using namespace genv;

Gamemaster::Gamemaster(int x, int y){
    X=x;
    Y=y;
    gout.open(X,Y);
}
void Gamemaster::cclear(){
    gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
}
void Gamemaster::register_widget(Widget* widget){
    w.push_back(widget);
}
void Gamemaster::delete_last_widget(){
    w.pop_back();
}
void Gamemaster::start_screen(){
    cclear();
    for (int i=0; i<2;i++){
        w[i]->draw();
    }
    gout << refresh;
    ismenu = true;
}
void Gamemaster::end_screen(int k){
    cclear();
    for (int i=2; i<5;i++){
        if (i!=k){
            w[i]->draw();
        }
    }
    gout<<refresh;
    isend = true;
}
void Gamemaster::is_five(){
    Kord s;
    int countervizplay1 = 1;
    int counterfugplay1 = 1;
    int countervizplay2 = 1;
    int counterfugplay2 = 1;
    int counterker1play1 = 1;
    int counterker1play2 = 1;
    int counterker2play1 = 1;
    int counterker2play2 = 1;
    for(int i=0; i<play1.size();i++){
        s.x=play1[i]->x;
        s.y=play1[i]->y;
        for(int k=0; k<play1.size();k++){
            if (play1[k]->x==s.x+40 && play1[k]->y==s.y){
                countervizplay1 ++;
            }
            if (play1[k]->y==s.y+40 && play1[k]->x==s.x){
                counterfugplay1 ++;
            }
            if (play1[k]->x== s.x+40 && play1[k]->y==s.y+40){
                counterker1play1++;
            }
            if (play1[k]->x==s.x-40 && play1[k]->y==s.y+40){
                counterker2play1++;
            }
            if (counterfugplay1 == 5 || countervizplay1==5 || counterker1play1==5 || counterker2play1==5){
                end_screen(3);
                break;
            }
        }
    }
    for(int i=0; i<play2.size();i++){
        s.x=play2[i]->x;
        s.y=play2[i]->y;
        for(int k=0; k<play2.size();k++){
            if (play2[k]->x==s.x+40 && play2[k]->y==s.y){
                countervizplay2 ++;
            }
            if (play2[k]->y==s.y+40 && play2[k]->x==s.x){
                counterfugplay2 ++;
            }
            if (play2[k]->x== s.x+40 && play2[k]->y==s.y+40){
                counterker1play2++;
            }
            if (play1[k]->x==s.x-40 && play1[k]->y==s.y+40){
                counterker2play2++;
            }
            if (counterfugplay2 == 5 || countervizplay2==5 || counterker1play2==5 || counterker2play2==5){
                end_screen(2);
                break;
            }
        }
    }
}
void Gamemaster::event_loop(){
    srand(time(0));
    start_screen();
    cclear();
    event ev;
    int prev = -1;
    gin.timer(120);
    while(gin >> ev && ev.keycode != key_escape) {
        if (ismenu){
            if (ev.button==btn_left){
                for (int i=0; i<2;i++){
                    if(w[i]->is_selected(ev.pos_x,ev.pos_y)){
                       w[i]->handle(ev);
                    }
                }
            }
        }
        else if(isend){
            if (ev.button==btn_left){
                for (int i=2; i<5;i++){
                    if(w[i]->is_selected(ev.pos_x,ev.pos_y)){
                       w[i]->handle(ev);
                    }
                }
            }
        }
        else{
            if (ev.button==btn_left){
                bool is_any_selected = false;
                for(int i=0; i<w.size();i++){
                    if(w[i]->is_selected(ev.pos_x,ev.pos_y)){
                        prev = i;
                        is_any_selected = true;
                    }
                }
                if(is_any_selected == false){
                    prev=-1;
                }
            }
            if (prev!=-1){
                w[prev]->handle(ev);
                prev = -1;
                is_five();
                if (witchplayer){
                    witchplayer=false;
                }
                else{
                    witchplayer=true;
                }
            }
            if (ev.type == ev_timer)
            {
                cclear();
                for(int i=0;i<w.size();i++)
                {
                    w[i]->draw();
                }
                gout << refresh;

            }
        }
    }
}
