#pragma once

#include "stdafx.h"

#define NUM_VERTICES 1

class AppMain
{
public:

	enum VAO_IDs
	{
		Triangles = 0,
		NumVAOs
	};

	enum Buffer_IDs
	{
		ArrayBuffer = 0,
		NumBuffers
	};

	enum Attrib_IDs
	{
		vPosition = 0
	};

	AppMain();
	~AppMain();

	bool Init();
	bool InitGL();
	bool Loop();
	void Update();
	void Render();
	void Events();
	void Destroy();

private:

	SDL_Window *	m_pWindow;
	SDL_GLContext	m_pGLContext;
	Uint32			m_start;
	bool			m_running;
	SDL_Event		m_event;

	// OpenGL vars

	GLuint			VAOs[NumVAOs];
	GLuint			Buffers[NumBuffers];
}; 