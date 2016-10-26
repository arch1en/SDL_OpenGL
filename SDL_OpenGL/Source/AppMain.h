#pragma once

#include "stdafx.h"
#include "Sampler.h"
#include "Factories\FactoryMesh.h"
#include "Renderers\Renderer.h"

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
	void InitializeComponents();
	bool Loop();
	void Update();
	void Render();
	void Events();
	void ErrorHandle(const char* msg);
	void Destroy();

private:

	SDL_Window *	Window;
	SDL_GLContext	GLContext;
	Uint32			Start;
	bool			Running;
	SDL_Event		Event;
	ShaderProgram	ShaderProgram;

	// OpenGL vars

	GLuint			mVAOs[NumVAOs];
	GLuint			Buffers[NumBuffers];

	std::shared_ptr<Renderer>		mRenderer;
	FactoryMesh						mFactoryMesh;

}; 