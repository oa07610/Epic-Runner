#include "lives.hpp"
#include <iostream>
//Lives bar implementation will go here.

lives::lives(){
    // src coorinates found using spritecow.com
    srcRect = {0, 0, 599, 478};
     // setting values
    moverRect = {30,40, 50, 50};
}

void lives::operator--(){
	l_left-=1;             //operator overloading. reduces the lives that are left by 1
}

void lives :: draw(){
	moverRect = {20,-30, 50, 50};               
	for(int i=0 ; i<l_left ; i++){            //to make the lives in a line
		if(i%5==0){//go to new line
			moverRect.x=30;
			moverRect.y+=50;
		}
		SDL_RenderCopy(Drawing::gRenderer, Drawing::life, &srcRect, &moverRect);   //makes the object
		moverRect.x+=40;		           // the object moves in the X-direction
	} 
}

lives :: ~lives(){							//Destructor to remove the instance
}