#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;         //Man Image
    static SDL_Texture* tt;             //Coin Image
    static SDL_Texture* cactus;         //Zombie Image
    static SDL_Texture* life;           //Life Image
    static SDL_Texture* ghost;          //Ghost Image
    static SDL_Texture* animal;         //Animal Image
    static SDL_Texture* meteor;         //Meteor Image
    static SDL_Texture* exp;            //Explosive Effect Image
};