#include "cactus.hpp"
#include <iostream>


cactus::cactus(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {67, 12, 119, 240};
     // setting pigeon x and y values
    moverRect = {980,500, 50, 50};
}

cactus::cactus(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {67, 12, 119, 240};
}


void cactus::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::cactus, &srcRect, &moverRect);  //makes the object
    if (frame == 0){srcRect = {320, 4, 125, 248};}
    else if (frame==1){srcRect = {550,22,157,230};}
    else if (frame==2){srcRect = {829,4,116,245};}
    else if (frame==3){srcRect = {1074,4,132,245};}
    else if (frame==4){srcRect = {1327,21,146,229} ;}
    frame++; 
    if (frame == 5){frame = 0;}
}

void cactus::move(){
    if (moverRect.x < 0){
        count ++;
        moverRect.x = 980;
        moverRect.x -= 10;}
    else{moverRect.x -= 10;}
}