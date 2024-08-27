#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "headers/main.h"

SDL_Window* gwindow = NULL;
SDL_Surface* gscreen_surface = NULL;
SDL_Surface* gmedia = NULL;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		printf("SDL couldn't initiate, SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gwindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!gwindow)
		{
			printf("Couldn't create window, SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gscreen_surface = SDL_GetWindowSurface(gwindow);
		}
	}

	return (success);
}

bool loadmedia()
{
	bool success = true;

	gmedia = SDL_LoadBMP("images/hello_world.bmp");
	if (!gmedia)
	{
		printf("Unable to load image, SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	return (success);
}

void end()
{
	SDL_FreeSurface(gmedia);
	gmedia = NULL;

	SDL_DestroyWindow(gwindow);
	gwindow = NULL;

	SDL_Quit();
}

int main(int argc, char *argv[])
{
	if (!init())
	{
		printf("Failed to initialize SDL");
	}
	else
	{
		if(!loadmedia())
		{
			printf("Failed to load image");
		}
		else
		{
			SDL_BlitSurface(gmedia, NULL, gscreen_surface, NULL);
			SDL_UpdateWindowSurface(gwindow);
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

	end();
	return(0);
}
