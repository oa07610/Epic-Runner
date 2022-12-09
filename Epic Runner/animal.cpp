#include "animal.hpp"
#include <iostream>


animal::animal(){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting the values
    srcRect = {67, 12, 119, 240};
}

void animal::draw(){         //this is the draw function
    SDL_RenderCopy(Drawing::gRenderer, Drawing::animal, &srcRect, &moverRect);  //draws the object
    //putting checks for the animation      //srcRect values taken from spritecow
    if (frame == 0){srcRect = {32, 26, 213, 173};}
    else if (frame==1){srcRect = {294, 24, 209, 173};}
    else if (frame==2){srcRect = {56, 24, 205, 174};}
    frame++;       //so that the frame/animation changes
    if (frame == 3){frame = 0;}
}

void animal::move(){
    moverRect.x -= 10;       //objects move to the left by 10 units 
}

animal :: ~animal(){          //destructor made to fully erase the existence of the object
}