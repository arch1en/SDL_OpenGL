////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Renderer
//  @author     : Artur Ostrowski
//  @usage      : Base class responsible for rendering tasks.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"
#include <stack>

#include "Components/MeshComponent.h"
#include "Rendering\ShaderProgram.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	/**
	*   Draws meshes that are on RenderingStack.
	*/
	void DrawMeshes(const GLsizei aVAOIndex, 
		const glm::mat4& aViewMatrix);

	void AddMeshToDraw(std::shared_ptr<MeshComponent> InMesh);
	void Initiate();
private:

	GLenum	DrawingMode;
	GLsizei	ParametersInOneVector;
	
	ShaderProgram	mShaderProgram;

	GLint mModelUniformLocation = -1;
	GLint mViewUniformLocation = -1;
	GLint mProjectionUniformLocation = -1;

	// Keeps all objects that needs to be rendered on the scene.
	std::vector<std::shared_ptr<MeshComponent>> Meshes;

};