#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class animal : public Unit{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    int frame = 0 ;
    void draw();
    void move();
    animal();
    animal(int, int);
};