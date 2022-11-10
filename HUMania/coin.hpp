#include<SDL.h>
#include "drawing.hpp"
class coin{
    friend class HUMania;
    SDL_Rect srcRect, moverRect;
    public:
    int counts = 0 ;
    void draw();
    coin();
};