////////////////////////////////////////////////////////////////
///
///		Main application of OpenGL program.
///		Here's what needs to be done:
///			1. Initialize SDL
///			2. Create Window.
///			3. Create OpenGL Context and bind it with the window.
///			4. Initialize GLEW (dont forget to glewExperimental = true; if you want to use modern OpenGL stuff.
///			5. Generate and Bind VAO and VBO and pass data into it.
///			6. Enable VSync.
///			7. Clear color to black and swap buffers.
///
////////////////////////////////////////////////////////////////

#include "AppMain.h"

AppMain::AppMain()
	: m_pWindow(nullptr)
	, m_pGLContext()
	, m_start(0)
	, m_running(false)
	, m_event()
	, VAOs()
	, Buffers()
	, m_ShaderProgram()
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
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	m_pWindow = SDL_CreateWindow("SDL_OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)WINDOW_WIDTH, (int)WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(!m_pWindow)
		g_sdldie("Unable to create SDL window");

	// Create Context
	m_pGLContext = SDL_GL_CreateContext(m_pWindow);
	if (!m_pGLContext)
		g_sdldie("Unable to create OpenGL Context");

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		g_sdldie("Error initializing GLEW! %s\n");
		printf("%s\n", glewGetErrorString(glewError));
	}
		
	// Initialize GLEW and Vertex data
	if (!InitGL())											// InitGL
		g_sdldie("Unable to initialize OpenGL");
	
	// This makes our buffer swap synchronized with monitor vertical refresh (VSync).
	if (SDL_GL_SetSwapInterval(1) < 0)
	{
		printf("Warning: Unable to set VSync. SDL Error ! : %s", SDL_GetError());
	}

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
	const int NumVertices = 1;

	if (glewInit())
	{
		g_sdldie("Unable to initialize glew");
		return false;
	}

	m_ShaderProgram.Init();

	m_ShaderProgram.LoadShader("Assets\\Shaders\\hello_glsl.vert", GL_VERTEX_SHADER);
	m_ShaderProgram.LoadShader("Assets\\Shaders\\hello_glsl.frag", GL_FRAGMENT_SHADER);

	m_ShaderProgram.LinkProgram();
	m_ShaderProgram.Bind();

	// Careful, can cause crash on glDrawArrays
	GLint posAttrib = glGetAttribLocation(m_ShaderProgram.getProgramID(), "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//VBO data 
	GLfloat vertexData[] = 
	{ 
		-0.5f, -0.5f, 
		0.5f, -0.5f, 
		0.5f, 0.5f, 
		-0.5f, 0.5f 
	}; 
	
	//IBO data 
	GLuint indexData[] = 
	{
		0, 1, 2, 3 
	}; 

	// Create VBO 
	glGenBuffers( 1, &mVBO ); 
	glBindBuffer( GL_ARRAY_BUFFER, mVBO ); 
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW ); 

	if (glGetError() != GL_NO_ERROR)
	{
		printf("Could not create VBO : %s \n", gluErrorString(glGetError()));
	}

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

