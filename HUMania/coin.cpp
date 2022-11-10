#include "coin.hpp"
#include <iostream>
//bee implementation will go here.


coin::coin(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {980,500, 50, 50};
     // setting pigeon x and y values
    srcRect = {0, 0, 30, 50};
}


void coin::draw(){
    moverRect = {20, 130, 50, 50};
	for(int i=0 ; i<counts ; i++){
		SDL_RenderCopy(Drawing::gRenderer, Drawing::tt, &srcRect, &moverRect);  
		moverRect.x+=40;		
	}
}
