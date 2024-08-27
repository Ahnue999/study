#include <stdbool.h>
#include "headers/main.h"

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 1000;
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
 * loadsurface - Loads media.
 * @file_name: name of the file to load.
 *
 * return: true when success, false otherwise.
 */
SDL_Surface* loadsurface(char *file_path)
{
	SDL_Surface* loaded_surface = NULL;
	SDL_Surface* optimized_surface = NULL;

	loaded_surface = SDL_LoadBMP(file_path);
	if (!loaded_surface)
	{
		printf("Unable to load image(%s), SDL_Error: %s\n",file_path,  SDL_GetError());
	}
	else
	{
		optimized_surface = SDL_ConvertSurface(loaded_surface, gscreen_surface->format, 0);
		if (!optimized_surface)
		{
			printf("Failed to optimize image %s, SDL_Error: %s\n", file_path, SDL_GetError());
		}
		SDL_FreeSurface(loaded_surface);
	}
	return (optimized_surface);
}


/**
* loadmedia - loads media.
*
* return: true when success and fasle otherwise.
*/
bool loadmedia()
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

int main(int argc, char *argv[])
{
	bool quit = false;
	SDL_Event e;
	SDL_Rect stretch_rect;

	if (!(gscreen_surface = init(&gwindow)))
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if (!loadmedia())
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

					stretch_rect.x = 0;
					stretch_rect.y = 0;
					stretch_rect.h = SCREEN_HEIGHT;
					stretch_rect.w = SCREEN_WIDTH;
					SDL_BlitScaled(gcurrent_surface, NULL, gscreen_surface, &stretch_rect);
					SDL_UpdateWindowSurface(gwindow);
				}
			}
		}
	}
	end();
	return(0);
}
