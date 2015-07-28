#pragma once

#include "stdafx.h"
#include "Sampler.h"

#define NUM_VERTICES 1

class AppMain
{
public:

	enum VAO_IDs
	{
		Triangles = 0,
		NumVAOs,
		NumVBOs
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
	void ErrorHandle(const char* msg);
	void Destroy();

private:

	SDL_Window *	m_pWindow;
	SDL_GLContext	m_pGLContext;
	Uint32			m_start;
	bool			m_running;
	SDL_Event		m_event;
	ShaderProgram	m_ShaderProgram;

	// OpenGL vars

	GLuint			mVAOs[NumVAOs];
	GLuint			mVBOs[NumVBOs];
	GLuint			mEBO;
	GLuint			Buffers[NumBuffers];
}; 