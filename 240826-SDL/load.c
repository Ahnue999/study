#include <stdbool.h>
#include "headers/main.h"

/**
 * loadsurface - Loads media.
 * @file_name: name of the file to load.
 *
 * return: true when success, false otherwise.
 */
SDL_Surface* loadsurface(char *file_path)
{
	SDL_Surface* loaded_surface = NULL;

	loaded_surface = SDL_LoadBMP(file_path);
	if (!loaded_surface)
	{
		printf("Unable to load image(%s), SDL_Error: %s\n",file_path,  SDL_GetError());
	}

	return (loaded_surface);
}

