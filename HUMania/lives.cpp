#include "lives.hpp"
#include <iostream>
//bee implementation will go here.

lives::lives(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0, 0, 599, 478};
     // setting pigeon x and y values
    moverRect = {30,40, 50, 50};
}


void lives :: draw(){
	moverRect = {20,-30, 50, 50};
	for(int i=0 ; i<l_left ; i++){
		if(i%5==0){//go to new line
			moverRect.x=30;
			moverRect.y+=50;
		}
		SDL_RenderCopy(Drawing::gRenderer, Drawing::life, &srcRect, &moverRect);  
		moverRect.x+=40;		
	}
}