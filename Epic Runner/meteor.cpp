#include "meteor.hpp"
#include <iostream>

meteor::meteor(){
    // setting the values randomly
    moverRect = {(200 + rand() % 780),0, 70, 70};
    // src coorinates found using spritecow.com
    srcRect = {212, 326, 1978, 1807};
    objType = rand() % 2;           //Randomly assigning, to choose movement in draw
}

void meteor::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::meteor, &srcRect, &moverRect);  //draws the object
}

void meteor::move(){
    if(objType==0){
        moverRect.x += 15;              //Meteor moves right by 15 units
        moverRect.y += 20;              //Meteor moves down by 20 units
    }
    else if(objType==1){
        moverRect.x -= 15;
        moverRect.y += 20;
    }
    else if(objType==2){
        moverRect.y += 20;
    }
}

meteor :: ~meteor(){        // virtual destructor called
}