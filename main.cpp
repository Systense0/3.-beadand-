#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "Gamemaster.hpp"
#include "Field.hpp"
#include "staticbox.hpp"
#include "Pushbutton.hpp"
using namespace genv;

class MyApp: public Gamemaster{
protected:
        Staticbox *st1;
        Pushbutton *pb1;
        Staticbox *st2;
        Staticbox *st3;
        Pushbutton *pb2;
        std::vector<Field*> f;
public:
    MyApp(int X, int Y): Gamemaster(X,Y){
        st1 = new Staticbox(this,100,100,400,100,"Amoba");
        pb1 = new Pushbutton(this, 220, 250, 150,100, "Start 2v2");
        st1 = new Staticbox(this,100,100,400,100,"Player1 won!");
        st1 = new Staticbox(this,100,100,400,100,"Player2 won!");
        pb2 = new Pushbutton(this, 210, 250, 200,100, "Back to menu");
        for (int i=0; i<=600; i+=40){
            for (int k=0; k<=600; k+=40){
                Field * f1;
                f1 = new Field(this,i,k,40,40);
                f.push_back(f1);
            }
        }
    }
};
int main()
{
    MyApp app(600,600);
    app.event_loop();
    return 0;
}
