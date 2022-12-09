#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class Man{
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;
public:
    void draw();        //draw function declared here
    Man();                //default constructor
    bool check;             //check used in RunningMan for jump checking
    void moving();          //moving function 
    void jump();            //jump function
    int i;                  // for horizontal animation 
    int frame = 0;          // for animation while jumping 
    ~Man();                 // destructor
};