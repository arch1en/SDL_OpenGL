#pragma once

#include "stdafx.h"
#include "Sampler.h"
#include "Factories\FactoryMesh.h"
#include "Rendering\Renderer.h"
#include "Rendering\ShaderProgram.h"
#include "Managers\InputManager.h"
#include "Scene\Camera.h"

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

	InputManager	mInputManager;
	Camera			mMainCamera;

	// OpenGL vars

	std::shared_ptr<Renderer>		mRenderer;
	FactoryMesh						mFactoryMesh;

}; 