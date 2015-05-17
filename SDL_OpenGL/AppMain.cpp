#include "AppMain.h"

AppMain::AppMain()
	:m_pWindow(nullptr)
{
}

AppMain::~AppMain()
{
	Destroy();
}

bool AppMain::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	m_pWindow = SDL_CreateWindow("SDL_OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)WINDOW_WIDTH, (int)WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(!m_pWindow)
		g_sdldie("Unable to create SDL window");

	m_pGLContext = SDL_GL_CreateContext(m_pWindow);
	if (!m_pGLContext)
		g_sdldie("Unable to create OpenGL Context");

	if (!InitGL())
		g_sdldie("Unable to initialize OpenGL");
	
	// This makes our buffer swap synchronized with monitor vertical refresh (VSync).
	SDL_GL_SetSwapInterval(1);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(m_pWindow);

	// Set the area to view in frustum.
	glViewport(0, 0, 600, 400);

	// Smooth the color
	glShadeModel(GL_SMOOTH);

	// 2D rendering
	glMatrixMode(GL_PROJECTION);

	// Reset viewport position to the origin.
	glLoadIdentity();

	//gluPerspective(45.0, WINDOW_WIDTH/WINDOW_HEIGHT, 1.0, 500.0);

	// Disable depth checking (game will be 2D, so its not nescessary. In 3D it would)
	glDisable(GL_DEPTH_TEST);

	m_running = true;

	return true;
}

bool AppMain::InitGL()
{

	if (glewInit())
	{
		g_sdldie("Unable to initialize glew");
		return false;
	}

	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat	vertices[NUM_VERTICES][2] = 
	{
		{ -0.90, -0.90 },
		{  0.85, -0.90 },
		{ -0.90,  0.85 },
		{  0.90, -0.85 },
		{  0.90,  0.90 },
		{ -0.85,  0.90 }
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	return true;
}

bool AppMain::Loop() 
{
	while (m_running)
	{
		m_start = SDL_GetTicks();
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
				case SDL_QUIT:
				{
					m_running = false;
					break;
				}
			}
		}
		Update();
		Render();
		SDL_GL_SwapWindow(m_pWindow);
	}
	return true;
}

void AppMain::Destroy()
{
	SDL_GL_DeleteContext(m_pGLContext);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

void AppMain::Update()
{

}

void AppMain::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NUM_VERTICES);

	glFlush();
}

void AppMain::Events()
{

}


