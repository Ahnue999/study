#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "headers/main.h"

int main(int argc, char* argv[])
{
	/*The window we'll be rendering to */
	SDL_Window* window = NULL;

	/*The surface contained by the window*/
	SDL_Surface* screen_surface = NULL;

	/*SDL initialize*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL couldn't initialize, SDL_ERROR: %s\n", SDL_GetError());
	}
	else
	{
		/*Create window*/
		window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!window)
		{
			printf("Window couldn't be created, SDL_ERROR: %s\n", SDL_GetError());
		}
		else
		{
			screen_surface = SDL_GetWindowSurface(window);

			SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);

			/*HACK to get window to stay up*/
			SDL_Event e;
			bool quit = false;
			while( quit == false )
			{
				while( SDL_PollEvent( &e ) )
				{
					if( e.type == SDL_QUIT )
						quit = true;
				}
			}
			/*Hack*/
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
