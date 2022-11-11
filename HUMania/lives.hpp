#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class lives: public Unit{
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;
public:
    void draw();
    lives();
    bool check;
    int l_left = 10;
};