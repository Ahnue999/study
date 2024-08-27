#include <stdbool.h>
#include "headers/main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window *gwindow = NULL;
SDL_Surface *gscreen_surface = NULL;
SDL_Surface *gstretched_surface = NULL;

SDL_Surface *gkey_press_surfaces[KEY_PRESS_SURFACE_TOTAL];

/**
 * init - initiate SDL.
 * @window: the window to make the surface in.
 *
 * return: the surface.
 */
SDL_Surface *init(SDL_Window **window)
{
	SDL_Surface *surface = NULL;
	int img_flags;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL, SDL_Error: %s", SDL_GetError());
	}
	else
	{
		gwindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!gwindow)
		{
			printf("Unable to create window, SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			img_flags = IMG_INIT_PNG;
			if (!(IMG_Init(img_flags) & img_flags))
			{
				printf("Unable to initiate SDL_Image, SDL_Image Error: %s\n", IMG_GetError());
			}
			else
			{
				surface = SDL_GetWindowSurface(gwindow);
			}
		}
	}

	return (surface);
}

/**
 * loadsurface - Loads media.
 * @file_name: name of the file to load.
 *
 * return: true when success, false otherwise.
 */
SDL_Surface *loadsurface(char *file_path)
{
	SDL_Surface *loaded_surface = NULL;
	SDL_Surface *optimized_surface = NULL;

	loaded_surface = IMG_Load(file_path);
	if (!loaded_surface)
	{
		printf("Unable to load IMG (%s), SDL_Img Error: %s\n", file_path, IMG_GetError());
	}
	else
	{
		optimized_surface = SDL_ConvertSurface(loaded_surface, gscreen_surface->format, 0);
		if (!optimized_surface)
		{
			printf("Unable to optimize img %s, SDL_Error: %s\n",\
		  file_path, SDL_GetError());
		}

		SDL_FreeSurface(loaded_surface);
	}

	return(optimized_surface);
}


/**
* loadmedia - loads media.
*
* return: true when success and fasle otherwise.
*/
bool loadmedia()
{
	bool success = true;

	gstretched_surface = loadsurface("images/loaded.png");
	if (!gstretched_surface)
	{
		printf("Failed to load image.\n");
	}

	return(success);
}

/**
 * end - Quits and cleans the program.
 *
 * return: No return.
 */
void end(void)
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
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				stretch_rect.x = 0;
				stretch_rect.y = 0;
				stretch_rect.h = SCREEN_HEIGHT;
				stretch_rect.w = SCREEN_WIDTH;
				SDL_BlitScaled(gstretched_surface, NULL, gscreen_surface, &stretch_rect);
				SDL_UpdateWindowSurface(gwindow);
			}
		}
	}
	end();
	return(0);
}
