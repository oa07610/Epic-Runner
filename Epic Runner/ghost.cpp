#include "ghost.hpp"
#include <iostream>


ghost::ghost(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {67, 12, 119, 240};
     // setting pigeon x and y values
    moverRect = {980,500, 50, 50};
}

ghost::ghost(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {67, 12, 119, 240};
}


void ghost::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::ghost, &srcRect, &moverRect);  //makes the object
    if (frame == 0){srcRect = {110, 53, 722, 1142};}
    else if (frame==1){srcRect = {1069, 38, 546, 1161};}
    else if (frame==2){srcRect = {1982, 52, 721, 1143};}
    frame++; 
    if (frame == 3){frame = 0;}
}

void ghost::move(){
    if (moverRect.x < 0){
        count ++;
        moverRect.x = 980;
        moverRect.x -= 13;}
    else{moverRect.x -= 13;}
}