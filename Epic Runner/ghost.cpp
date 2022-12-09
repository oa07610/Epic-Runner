#include "ghost.hpp"
#include <iostream>

ghost::ghost(){
    // src coorinates using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting x and y values
    srcRect = {67, 12, 119, 240};
}

void ghost::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::ghost, &srcRect, &moverRect);  //draws the object
    if (frame == 0){srcRect = {110, 53, 722, 1142};}       //the code below is how the state chnages
    else if (frame==1){srcRect = {1069, 38, 546, 1161};}
    else if (frame==2){srcRect = {1982, 52, 721, 1143};}
    frame++;                 //so that the frame/animation changes
    if (frame == 3){frame = 0;}
}

void ghost::move(){
    moverRect.x -= 15;         //ghost moves 15 unit to the left.
}

ghost :: ~ghost(){          //virtaul destructor made here;
     
}