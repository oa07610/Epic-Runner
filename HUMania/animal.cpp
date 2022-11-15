#include "animal.hpp"
#include <iostream>


animal::animal(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {67, 12, 119, 240};
     // setting pigeon x and y values
    moverRect = {980,500, 50, 50};
}

animal::animal(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {67, 12, 119, 240};
}


void animal::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::animal, &srcRect, &moverRect);  //makes the object
    if (frame == 0){srcRect = {32, 26, 213, 173};}
    else if (frame==1){srcRect = {294, 24, 209, 173};}
    else if (frame==2){srcRect = {56, 24, 205, 174};}
    frame++; 
    if (frame == 3){frame = 0;}
}

void animal::move(){
    if (moverRect.x < 0){
        count ++;
        moverRect.x = 980;
        moverRect.x -= 10;}
    else{moverRect.x -= 10;}
}