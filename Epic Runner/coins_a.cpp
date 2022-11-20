#include "coins_a.hpp"
#include <iostream>
//Bottom path coins implementation will go here.

coins_a::coins_a(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0, 0, 30, 50};
     // settingx and y values
    moverRect = {980,500, 50, 50};
}

coins_a::coins_a(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {0, 0, 30, 50};
}


void coins_a::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::tt, &srcRect, &moverRect);  //makes the object
}

void coins_a::move(){
    if (moverRect.x < 0){
        count ++;
        moverRect.x = 980;
        moverRect.x -= 20;}
    else{moverRect.x -= 20;}
}