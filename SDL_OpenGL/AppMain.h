#pragma once

#include "stdafx.h"

class AppMain
{
public:

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

	SDL_Window * m_pWindow;
	SDL_GLContext m_pGLContext;
	Uint32	m_start;
	bool	m_running;
	SDL_Event m_event;
}; 