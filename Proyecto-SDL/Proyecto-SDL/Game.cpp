#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
int posX = 0;
int posY = 0;
int speed = 30;

Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fulscreen)
{
	int flags = 0; 
	if(fulscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystem Initialized" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			cout << "Window created!" << endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created!" << endl;
		}
		isRunning = true;
	}
	else
		isRunning = false;

	SDL_Surface* tmpSurface = IMG_Load("assets/Key.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{	
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			destR.x -= 10;
			break;
		case SDLK_RIGHT:
			destR.x += 10;
			break;
		case SDLK_UP:
			destR.y -= 10;
			break;
		case SDLK_DOWN:
			destR.y += 10;
			break;								
		case SDLK_ESCAPE:
				isRunning = false;
				break;
		}
	}
}
void Game::Update()
{
	destR.h = 32;
	destR.w = 32;	
	
}
void Game::Render() 
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}
bool Game::Running() 
{
	return isRunning;
}
void Game::checkBoundaries() 
{

}

