#include <stdbool.h>
#include "headers/main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window *gwindow = NULL;
SDL_Renderer *grenderer = NULL;
SDL_Texture *gtexture = NULL;
SDL_Texture *gtexture2 = NULL;

/**
 * init - initiate SDL.
 * @window: the window to make the surface in.
 *
 * return: the surface.
 */
bool init(SDL_Window **window)
{
	bool success = true;
	int img_flags;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL, SDL_Error: %s", SDL_GetError());
		success = false;
	}
	else
	{
		gwindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!gwindow)
		{
			printf("Unable to create window, SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			grenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);
			if (!grenderer)
			{
				printf("Unable to create Renderer, SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(grenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				img_flags = IMG_INIT_PNG;
				if (!(IMG_Init(img_flags) & img_flags))
				{
					printf("Unable to initiate SDL_Img, SDL_Image Error: %s\n", IMG_GetError);
					success = false;
				}
			}
		}
	}
	return (success);
}

/**
 * loadsurface - Loads media.
 * @file_name: name of the file to load.
 *
 * return: true when success, false otherwise.
 */
SDL_Texture *loadtexture(char *file_path)
{
	SDL_Surface *loaded_surface = NULL;
	SDL_Texture *new_texture = NULL;

	loaded_surface = IMG_Load(file_path);
	if (!loaded_surface)
	{
		printf("Unable to load IMG (%s), SDL_Img Error: %s\n", file_path, IMG_GetError());
	}
	else
	{
		new_texture = SDL_CreateTextureFromSurface(grenderer, loaded_surface);
		if (!new_texture)
		{
			printf("Unable to create Texture, SDL_Error %s\n", SDL_GetError());
		}
	}

	SDL_FreeSurface(loaded_surface);

	return(new_texture);
}

/**
* loadmedia - loads media.
*
* return: true when success and fasle otherwise.
*/
bool loadmedia(char *file_path)
{
	bool success = true;

	gtexture = loadtexture("images/viewport.png");
	if (!gtexture)
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
	SDL_DestroyTexture(gtexture);
	gtexture = NULL;

	SDL_DestroyRenderer(grenderer);
	SDL_DestroyWindow(gwindow);
	gwindow = NULL;
	grenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	bool quit = false;
	SDL_Event e;

	if (!init(&gwindow))
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if (!loadmedia("images/viewport.png"))
		{
			printf("Couldn't load media\n");
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

				SDL_Rect topleft = {0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_RenderSetViewport(grenderer, &topleft);
				SDL_RenderCopy(grenderer, gtexture, NULL, NULL);

				SDL_Rect topright = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_RenderSetViewport(grenderer, &topright);
				SDL_RenderCopy(grenderer, gtexture, NULL, NULL);

				SDL_Rect bottom = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
				SDL_RenderSetViewport(grenderer, &bottom);
				SDL_RenderCopy(grenderer, gtexture, NULL, NULL);

				SDL_RenderPresent(grenderer);
			}
		}
	}
	end();
	return(0);
}
