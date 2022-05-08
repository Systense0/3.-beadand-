#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <Gamemaster.hpp>
using namespace genv;
<<<<<<< HEAD
///EZ EGY COMMENT!!!!!
=======
///EZ EGY COMMENT!!!!!:))
>>>>>>> Feature
class MyApp: public Gamemaster{
protected:
    Spinbox * sb1;
    Spinbox * sb2;
    Dropdown * dd1;
    Dropdown * dd2;
public:
    MyApp(int X, int Y): Application(X,Y){
        sb1 = new Spinbox(this,20,30,200,40,0,20,0);
        sb2 = new Spinbox(this,260,30,150,30,-50,50,0);
        dd1 = new Dropdown(this,20,100,200,40,"January|February|March|April|May|June|July|August|September|October|November|December",3);
        dd2 = new Dropdown(this,260,100,150,50, "Red|Green|Blue|Yellow|Purple|Pink",2);
    }
    void action(std::string id){
        if (id == "save"){
            std::ofstream myfile ("ertekek.txt");
            if (myfile.is_open()){
                myfile << sb1->renumb() << "\n";
                myfile << sb2->renumb() << "\n";
                myfile << dd1->retext() << "\n";
                myfile << dd2->retext() << "\n";
                myfile.close();
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
