#include <stdbool.h>
#include "headers/main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
 * init - initiate SDL.
 * @window: the window to make the surface in.
 *
 * return: the surface.
 */
SDL_Surface* init(SDL_Window** window)
{
	SDL_Surface *screen_surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		printf("SDL couldn't initiate, SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		*window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,\
							 SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,\
							 SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!*window)
		{
			printf("Couldn't create window, SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screen_surface = SDL_GetWindowSurface(*window);
		}
	}

	return (screen_surface);
}

/**
 * end - Quits and cleans the program.
 *
 * return: No return.
 */
void end(SDL_Window** window, SDL_Surface** surface)
{
	SDL_FreeSurface(*surface);
	*surface = NULL;

	SDL_DestroyWindow(*window);
	*window = NULL;

	SDL_Quit();
}

int main(int argc, char *argv[])
{

	SDL_Window* window = NULL;
	SDL_Surface* screen_surface = NULL;
	SDL_Surface* hello_surface = NULL;
	SDL_Surface* x_surface = NULL;
	bool quit = false;
	SDL_Event e;

	if (!(screen_surface = init(&window)))
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if(!(x_surface = loadsurface("images/x.bmp")))
		{
			printf("Failed to load image");
		}
		else
		{
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = true;
				}

				SDL_BlitSurface(x_surface, NULL, screen_surface, NULL);
				SDL_UpdateWindowSurface(window);
			}
		}
	}

	end(&window, &x_surface);
	return(0);
}

