#include<SDL.h>
#include "drawing.hpp"
class apple{
    friend class HUMania;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    void draw();
    void move();
    apple();
    apple(int, int);
};