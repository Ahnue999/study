#include <stdio.h>
#include <string>
#include "headers/main.h"

SDL_Window *gwindow = NULL;
SDL_Renderer *grenderer = NULL;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool load_from_file(std::string path);

		void free_t();

		void render(int x, int y);

		int get_width();
		int get_height();

	private:
		SDL_Texture *m_texture;
		int m_width;
		int m_height;
};

LTexture g_foo_t;
LTexture g_background_t;

LTexture::LTexture()
{
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
}

LTexture::~LTexture()
{
	free_t();
}

bool LTexture::load_from_file(std::string path)
{
	SDL_Surface *loaded_surface = NULL;
	SDL_Texture *new_texture = NULL;
	free_t();

	loaded_surface = IMG_Load(path.c_str());
	if (!loaded_surface)
	{
		printf("Unable to load image: %s, IMG_Error: %s", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));
		new_texture = SDL_CreateTextureFromSurface(grenderer, loaded_surface);
		if (!new_texture)
		{
			printf("Unable to create texture from %s, SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			m_width = loaded_surface->w;
			m_height = loaded_surface->h;
		}

		SDL_FreeSurface(loaded_surface);
	}

	m_texture = new_texture;
	return(m_texture != NULL);
}

void LTexture::free_t()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		m_width = 0;
		m_height = 0;
	}
}

void LTexture::render(int x, int y)
{
	SDL_Rect render_quad = {x, y, m_width, m_height};
	SDL_RenderCopy(grenderer, m_texture, NULL, &render_quad);
}

int LTexture::get_width()
{
	return (m_width);
}

int LTexture::get_height()
{
	return (m_height);
}

/**
 * loadmedia - loads media.
 *
 * Return: true when success and false otherwise.
 */
bool loadmedia()
{
	bool success = true;

	if (!g_foo_t.load_from_file("images/foo.png"))
	{
		printf("Unable to load foo' texture image\n");
		success = false;
	}
	if (!g_background_t.load_from_file("images/background.png"))
	{
		printf("Unable to load foo' texture image\n");
		success = false;
	}

	return (success);
}

/**
 * end - close and cleans the program.
 *
 * Return: None.
 */
void end(void)
{
	g_foo_t.free_t();
	g_background_t.free_t();

	SDL_DestroyWindow(gwindow);
	SDL_DestroyRenderer(grenderer);
	gwindow = NULL;
	grenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

/**
 * init - initiate SDL.
 * @window: the window to make the surface in.
 *
 * Return: the surface.
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
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

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
 * main - entry point.
 *
 * Return: always 0.
 */
int main(void)
{
	bool quit = false;
	SDL_Event e;

	if (!init(&gwindow))
	{
		printf("Unable to initiate window, SDL_Error: %s", SDL_GetError());
	}
	else
	{
		if (!loadmedia())
		{
			printf("Unable to load media\n");
		}
		else
		{
			while(!quit)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				/*Clear Screen*/
				SDL_SetRenderDrawColor(grenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(grenderer);

				g_background_t.render(0, 0);
				g_foo_t.render(240, 190);

				SDL_RenderPresent(grenderer);
			}

		}
	}

	end();
	return (0);
}
