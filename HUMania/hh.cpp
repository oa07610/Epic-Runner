#include "hh.hpp"
#include <iostream>
//bee implementation will go here.

apple::apple(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0, 0, 30, 50};
     // setting pigeon x and y values
    moverRect = {980,500, 50, 50};
}

apple::apple(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {0, 0, 30, 50};
}


void apple::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::tt, &srcRect, &moverRect);  //makes the object
}

void apple::move(){
    if (moverRect.x < 0){
        count ++;
        moverRect.x = 980;
        moverRect.x -= 20;}
    else{moverRect.x -= 20;}
}