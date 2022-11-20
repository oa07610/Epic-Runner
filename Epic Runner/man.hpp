#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class Man: public Unit{
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;
public:
    void draw();
    Man();
    bool check;
    Man(int, int);
    void fly();
    void jump();
    int i;
    int frame = 0;
};