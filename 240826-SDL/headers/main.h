#ifndef _MAIN_H_
#define _MAIN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>


enum key_press {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_TOTAL
};

/* Functions */
/*SDL_Surface* init(SDL_Window** window);*/
bool init(SDL_Window **window);
SDL_Surface* loadsurface(char *file_path);
bool load_press_surfaces();
void end();

#endif
