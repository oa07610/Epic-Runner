#include<SDL.h>
#include "drawing.hpp"
class weapon{
    friend class HUMania;
    SDL_Rect srcRect, moverRect;
    public:
    void draw();
    weapon();
    weapon(int , int);
};