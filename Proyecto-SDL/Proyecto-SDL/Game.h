#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;
class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fulscreen);
	
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running();

private:
	void checkBoundaries();
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif
