#include <SDL.h>
#include "drawing.hpp"
#include <iostream>
using namespace std;
#pragma once

class Unit{             //defining a class named unit as required that is to be inherited by bee, pigeon, and butterfly.
    protected:
        SDL_Rect srcRect, moverRect;            //These values will be inherited by bee, pigeon, and butterfly. This would contain initial srcRect, moverRect values.
        int animation = 0;                  //An animation variable that will be inherited by bee, pigeon, and butterfly to animate objects.
    public:
        void draw();                           //A predefined draw function that will be inherited by bee, pigeon, and butterfly to draw objects.
        virtual void move();     //A virtual fly function since each object have different srcRect values for animation, this function cannot be predefined but would be defined individually in each class.
        friend class RunningMan;
};