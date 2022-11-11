#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;
    static SDL_Texture* coin;
    static SDL_Texture* cactus;
    static SDL_Texture* life;
    static SDL_Texture* weapon;
};