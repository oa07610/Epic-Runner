#include "game.hpp"
#include "RunningMan.hpp"
#include "drawing.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;
SDL_Texture* Drawing::tt = NULL;
SDL_Texture* Drawing::cactus = NULL;
SDL_Texture* Drawing::life = NULL;
SDL_Texture* Drawing::weapon = NULL;
SDL_Texture* Drawing::animal = NULL;
SDL_Texture* Drawing::ghost = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadGrid()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets.png");
	Drawing::tt = loadTexture("tt.png");
	Drawing::cactus = loadTexture("cactus.png");
	Drawing::life = loadTexture("life.png");
	Drawing::weapon = loadTexture("weapon.png");
	Drawing::animal = loadTexture("animal.png");
	Drawing::ghost = loadTexture("ghost.png");
    gTexture = loadTexture("bg.png");
	if(Drawing::assets==NULL || Drawing::tt==NULL || Drawing::life==NULL|| Drawing::weapon==NULL|| Drawing::cactus==NULL || Drawing::animal==NULL || Drawing::ghost==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
    gTexture = loadTexture("menu.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}


void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(Drawing::tt);
	Drawing::tt=NULL;
	SDL_DestroyTexture(Drawing::weapon);
	Drawing::weapon=NULL;
	SDL_DestroyTexture(Drawing::cactus);
	Drawing::cactus=NULL;
	SDL_DestroyTexture(Drawing::life);
	Drawing::life=NULL;
	SDL_DestroyTexture(Drawing::animal);
	Drawing::animal=NULL;
	SDL_DestroyTexture(Drawing::ghost);
	Drawing::ghost=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	RunningMan runningman;

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				cout<<quit;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (state == 0){
					state = 1;
					loadGrid();}
				else if (state ==1){runningman.createObject(xMouse, yMouse);}
			}
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP]) { 
				runningman.checks = true;
			}
			if (state[SDL_SCANCODE_RIGHT]) { 
				runningman.right = true;
			}
			if (state[SDL_SCANCODE_DOWN]) { 
				runningman.weapon_check = true;
			}
			if (state[SDL_SCANCODE_LEFT]) { 
				runningman.left = true;
			}
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		if (state ==1){
		runningman.drawObjects();}
		if (state ==1 && runningman.screen ==true){
		runningman.createObj();}

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(60);	//causes sdl engine to delay for specified miliseconds
	}
			
}
