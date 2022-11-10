#include<SDL.h>
#include "drawing.hpp"
class lives{

    SDL_Rect srcRect, moverRect;
    friend class HUMania;
public:
    void draw();
    lives();
    bool check;
    int l_left = 10;
};