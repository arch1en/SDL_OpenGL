////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Renderer
//  @author     : Artur Ostrowski
//  @usage      : Base class responsible for rendering tasks.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "Renderer.h"
Renderer::Renderer()
{
	DrawingMode = GL_TRIANGLES;
	ParametersInOneVector = 3;
}

Renderer::~Renderer()
{

}

void Renderer::AddMeshToDraw(std::shared_ptr<MeshBase> InMesh)
{
	Meshes.push_back(InMesh);
}

void Renderer::DrawMeshes()
{
	for (auto& iter : Meshes)
	{
		assert(iter != nullptr);
		//glDrawArrays(DrawingMode, 0, 3);
		glDrawElements(DrawingMode, ParametersInOneVector, GL_UNSIGNED_INT, 0);// &iter->mPolygonData.Elements[0]);
		// TODO [High] : Handle VAO Binding !

	}
}