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
	, mVAOs()
	, mVBOs()
	, mEBO()
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
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
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
	glClear(GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(m_pWindow);

	// Set the area to view in frustum.
	glViewport(0, 0, 640, 480);

	// Smooth the color
	glShadeModel(GL_SMOOTH);

	// 2D rendering
	glMatrixMode(GL_PROJECTION);

	// Reset viewport position to the origin.
	glLoadIdentity();

	gluPerspective(45.0, WINDOW_WIDTH/WINDOW_HEIGHT, 1.0, 500.0);

	// Disable depth checking (game will be 2D, so its not nescessary. In 3D it would)
	//glDisable(GL_DEPTH_TEST);

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

	glEnable(GL_DEPTH_TEST);

	m_ShaderProgram.Init();

	m_ShaderProgram.LoadShader("Assets\\Shaders\\hello_glsl.vert", GL_VERTEX_SHADER);
	m_ShaderProgram.LoadShader("Assets\\Shaders\\hello_glsl.frag", GL_FRAGMENT_SHADER);

	m_ShaderProgram.LinkProgram();
	m_ShaderProgram.Bind();

	glBindAttribLocation(m_ShaderProgram.getProgramID(), 0, "vertexPosition");
	glBindAttribLocation(m_ShaderProgram.getProgramID(), 1, "vertexColor");
	glBindFragDataLocation(m_ShaderProgram.getProgramID(), 0, "outColor");
	//VBO data
	struct Vertex
	{
		float x, y, z;
		float r, g, b;
	};

	Vertex triangle[] =
	{
		// Position			Color
		+0.0f, +1.0f, +0.0f, +1.0f, +0.0f, +0.0f,
		-1.0f, -1.0f, +0.0f, +0.0f, +1.0f, +0.0f,
		+1.0f, -1.0f, +0.0f, +0.0f, +0.0f, +1.0f,
	};

	// Texture test vertices
	
	// EBO data 
	GLuint indexData[] = 
	{
		0, 1, 2,
	}; 

	////////////////////////////////////////////////////////////////
	///
	///		The correct order of initializing buffers is:
	///		1. Vertex Array Object (VAO)
	///		2. Vertex Buffer Object (VBO)
	///
	///		After that we can use functions like glVertexAttribPointer.
	///		Without both these buffers binded to context, we would have UB.
	///
	////////////////////////////////////////////////////////////////

	// Create VAO
	glGenVertexArrays(NUM_VERTICES, mVAOs);
	glBindVertexArray(mVAOs[0]);

	// Create VBO 
	glGenBuffers(1, mVBOs);
	// Bind vertex data with the VBO
	glBindBuffer(GL_ARRAY_BUFFER, mVBOs[0]);
	// Allocate memory and populate the position buffer with vertexData.
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
	ErrorHandle("VertexBufferObject (VBO) : ");

	// Create EBO
	glGenBuffers(1, &mEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
	ErrorHandle("ElementBufferObject (EBO) : ");

	// After we have generated VAO and VBO we can pass data to vertex shader.
	GLint posAttrib = glGetAttribLocation(m_ShaderProgram.getProgramID(), "position");
	// Enable vertexPosition
	glEnableVertexAttribArray(posAttrib);
	// Pass data to the vertexPosition variable in the vertex shader.
	//glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(m_ShaderProgram.getProgramID(), "color");
	glEnableVertexAttribArray(colAttrib);
	//glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (char*)(3 * sizeof(GLfloat)));

	//GLint texAttrib = glGetAttribLocation(m_ShaderProgram.getProgramID(), "texcoord");
	//glEnableVertexAttribArray(texAttrib);
	//glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

	// Set VAO and VBO back to 0, to avoid unwanted data passing.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	ErrorHandle("VertexAttribPointer : ");
	
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

void AppMain::Update()
{

}

void AppMain::Render()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Last binded vertex array will be drawn by OpenGL, thus we will bind VAO
	glBindVertexArray(mVAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, mVBOs[0]);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0);

	glFlush();
}

void AppMain::Events()
{

}

void AppMain::ErrorHandle(const char* msg)
{
	printf(msg);
	switch (glGetError())
	{
		case GL_NO_ERROR:
			printf("GL_NO_ERROR");
		break;
		case GL_INVALID_ENUM:
			printf("GL_INVALID_ENUM");
		break;
		case GL_INVALID_VALUE:
			printf("GL_INVALID_VALUE");
		break;
		case GL_INVALID_OPERATION:
			printf("GL_INVALID_OPERATION");
		break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			printf("GL_INVALID_FRAMEBUFFER_OPERATION");
		break;
		case GL_OUT_OF_MEMORY:
			printf("GL_OUT_OF_MEMORY");
		break;
		case GL_STACK_UNDERFLOW:
			printf("GL_STACK_UNDERFLOW");
		break;
		case GL_STACK_OVERFLOW:
			printf("GL_STACK_OVERFLOW");
		break;
		default:
			break;
	}
	printf("\n");
}

void AppMain::Destroy()
{
	SDL_GL_DeleteContext(m_pGLContext);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
	glDeleteBuffers(1, &mEBO);


}

