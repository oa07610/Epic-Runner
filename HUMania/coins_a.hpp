#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class coins_a : public Unit{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    void draw();
    void move();
    coins_a();
    coins_a(int, int);
};