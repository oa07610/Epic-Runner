#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class coins_b{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int counts = 0 ;
    void draw();
    coins_b();
};