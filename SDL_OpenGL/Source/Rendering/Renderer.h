#pragma once

#include "../stdafx.h"
#include <stack>

#include "Mesh/MeshBase.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	/**
	*   Draws meshes that are on RenderingStack.
	*/
	void DrawMeshes();
	void AddMeshToDraw(std::shared_ptr<MeshBase> InMesh);

private:

	GLenum	DrawingMode;
	GLsizei	ParametersInOneVector;
	
	// Keeps all objects that needs to be rendered on the scene.
	std::vector<std::shared_ptr<MeshBase>> Meshes;

};