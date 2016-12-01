#pragma once

// *** SDL and OpenGL
#include <SDL.h>
#include <GL\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

// *** Mathematics ***
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Math/Math.h"

// *** Standard Template Libraries ***
#include <stdio.h>
#include <fstream>
#include <vector>		// Vector container
#include <memory>		// Smart pointers, smaller datatypes (uint8_t)

// *** Project Classes ***
#include "Debuggers/DebugTimer.h"
#include "Debuggers/Debugger.h"

using glm::mat4;
using glm::vec3;

#ifndef __FUNCTION__ 
#define __FUNCTION__ __func__
#endif

#define BIT(x) (1<<x)
#define SEC(x) x*1000

#define WINDOW_WIDTH	1280.0	
#define WINDOW_HEIGHT	720.0	

#define EXIT_FAILURE	1

#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))

// *** PLATFORM DEFINES ***

#define PLATFORM_WINDOWS
//#define PLATFORM_UNIX
//#define PLATFORM_MACOS
//#define PLATROFM_ANDROID
//#define PLATFORM_IOS

// ~~~ PLATFORM DEFINES ~~~

static void g_sdldie(const char* text);

inline void g_sdldie(const char* text)
{
	printf("%s : %s", text, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

// *** TYPEDEFS ***
typedef int32_t EnumBit;
typedef int32_t ArrayIndex;
// ~~~ TYPEDEFS ~~~