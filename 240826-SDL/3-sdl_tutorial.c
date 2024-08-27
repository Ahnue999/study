#include <stdbool.h>
#include "headers/main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gwindow = NULL;
SDL_Surface* gscreen_surface = NULL;
SDL_Surface* gcurrent_surface = NULL;

SDL_Surface* gkey_press_surfaces[KEY_PRESS_SURFACE_TOTAL];

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
void end()
{
	int i;

	for (i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface(gkey_press_surfaces[i]);
		gkey_press_surfaces[i] = NULL;
	}

	SDL_DestroyWindow(gwindow);
	gwindow = NULL;

	SDL_Quit();
}

/**
* loadmedia - loads media.
*
* return: true when success and fasle otherwise.
*/
bool load_press_surfaces()
{
	bool success = true;

	gkey_press_surfaces[KEY_PRESS_SURFACE_DEFAULT] = loadsurface("images/press.bmp");
	if (!gkey_press_surfaces[KEY_PRESS_SURFACE_DEFAULT])
	{
		printf("Unable to load 'default' image");
	}

	gkey_press_surfaces[KEY_PRESS_SURFACE_UP] = loadsurface("images/up.bmp");
	if (!gkey_press_surfaces[KEY_PRESS_SURFACE_UP])
	{
		printf("Unable to load 'UP' image");
	}

	gkey_press_surfaces[KEY_PRESS_SURFACE_RIGHT] = loadsurface("images/right.bmp");
	if (!gkey_press_surfaces[KEY_PRESS_SURFACE_RIGHT])
	{
		printf("Unable to load 'right' image");
	}

	gkey_press_surfaces[KEY_PRESS_SURFACE_DOWN] = loadsurface("images/down.bmp");
	if (!gkey_press_surfaces[KEY_PRESS_SURFACE_DOWN])
	{
		printf("Unable to load 'down' image");
	}

	gkey_press_surfaces[KEY_PRESS_SURFACE_LEFT] = loadsurface("images/left.bmp");
	if (!gkey_press_surfaces[KEY_PRESS_SURFACE_LEFT])
	{
		printf("Unable to load 'left' image");
	}

	return(success);
}

int main(int argc, char *argv[])
{

	bool quit = false;
	SDL_Event e;

	if (!(gscreen_surface = init(&gwindow)))
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if (!load_press_surfaces())
		{
			printf("Failed to load media\n");
		}
		else
		{
			gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_DEFAULT];

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
							case SDLK_UP:
							gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_UP];
							break;

							case SDLK_RIGHT:
							gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

							case SDLK_DOWN:
							gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_DOWN];
							break;

							case SDLK_LEFT:
							gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_LEFT];
							break;

							default:
							gcurrent_surface = gkey_press_surfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
					SDL_BlitSurface(gcurrent_surface, NULL, gscreen_surface, NULL);
					SDL_UpdateWindowSurface(gwindow);
				}
			}
		}
	}

	end();
	return(0);
}
