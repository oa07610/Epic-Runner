#include<SDL.h>
#include "drawing.hpp"
class cactus{
    friend class HUMania;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    int frame = 0 ;
    void draw();
    void move();
    cactus();
    cactus(int, int);
};