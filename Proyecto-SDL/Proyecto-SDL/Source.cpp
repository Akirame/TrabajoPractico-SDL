#include <SDL.h>
#include <stdio.h>

int main(int arcg, char*args[]) 
{
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Ventana muy piola", 32, 10, 640, 480, SDL_WINDOW_OPENGL);
	SDL_Event event;
	bool quit = false;

	if (window == NULL) 
	{
		printf("No se pudo crear ventana");
		return 1;
	}
	while(!quit)
	if (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{		
		case SDL_KEYDOWN:
			SDL_DestroyWindow(window);
			SDL_Quit();
			quit = true;
			break;
		}
	}
	return 0;
}