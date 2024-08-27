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
	SDL_Surface* media = NULL;

	if (!(screen_surface = init(&window)))
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if(!(media = loadmedia("images/hello_world.bmp")))
		{
			printf("Failed to load image");
		}
		else
		{
			SDL_BlitSurface(media, NULL, screen_surface, NULL);
			SDL_UpdateWindowSurface(window);
		}
	}

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

	end(&window, &media);
	return(0);
}

