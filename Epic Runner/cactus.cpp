#include "cactus.hpp"
#include <iostream>

cactus::cactus(){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting the values
    srcRect = {67, 12, 119, 240};
}

void cactus::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::cactus, &srcRect, &moverRect);  //draws the object
    //putting checks for the animation      //srcRect values taken from spritecow
    if (frame == 0){srcRect = {320, 4, 125, 248};}
    else if (frame==1){srcRect = {550,22,157,230};}
    else if (frame==2){srcRect = {829,4,116,245};}
    else if (frame==3){srcRect = {1074,4,132,245};}
    else if (frame==4){srcRect = {1327,21,146,229} ;}
    frame++;         //so that the frame/animation changes
    if (frame == 5){frame = 0;}
}

void cactus::move(){
    moverRect.x -= 7;       //objects move to the left by 7 units 
}

cactus :: ~cactus(){            //destructor made to fully erase the existence of the object
}