#include "weapon.hpp"
#include <iostream>
//bee implementation will go here.

weapon::weapon(int x,int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x, y, 50, 50};
     // setting pigeon x and y values
    srcRect = {13, 32, 91, 91};
}

weapon::weapon(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {50,50, 50, 50};
     // setting pigeon x and y values
    srcRect = {13, 32, 91, 91};
}

void weapon::draw(){
		SDL_RenderCopy(Drawing::gRenderer, Drawing::weapon, &srcRect, &moverRect);  
		moverRect.x+=10;}