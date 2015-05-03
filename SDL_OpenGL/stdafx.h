#pragma once

#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>

#define BIT(x) (1<<x)
#define SEC(x) x*1000

#define WINDOW_WIDTH	640.0
#define WINDOW_HEIGHT	480.0

#define EXIT_FAILURE	1

static void g_sdldie(const char* text);

inline void g_sdldie(const char* text)
{
	printf("%s : %s", text, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}