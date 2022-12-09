#include "explosion.hpp"
#include <iostream>

explosion::explosion(){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {980,500, 70, 70};
     // setting the values
    srcRect = {17, 0, 223, 240};
}

explosion::explosion(int x, int y){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {x, y, 80, 80};
     // setting the values
    srcRect = {17, 0, 223, 240};
}

void explosion::draw(){         //this is the draw function
    SDL_RenderCopy(Drawing::gRenderer, Drawing::exp, &srcRect, &moverRect);  //draws the object
}

explosion :: ~explosion(){          //destructor called to fully erase the existence of the object    
}