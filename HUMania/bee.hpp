#include<SDL.h>
#include "drawing.hpp"
class Bee{

    SDL_Rect srcRect, moverRect;
    friend class HUMania;
public:
    void draw();
    Bee();
    bool check;
    Bee(int, int);
    void fly();
    void jump();
    int i;
    int frame = 0;
};