////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Handles creation of new meshes onto the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "FactoryMesh.h"
#include "Mesh/MeshBase.h"
#include "Mesh/MeshTriangle.h"

FactoryMesh::FactoryMesh(std::shared_ptr<Renderer> InRenderer)
	: mRenderer{ InRenderer }
{

}

void FactoryMesh::Initialize()
{
	mAllocatorGPU.Initialize();
}

std::shared_ptr<MeshBase> FactoryMesh::NewMesh(MeshType InMeshType)
{
	std::shared_ptr<MeshBase> NewMesh;

	if (InMeshType == MeshType::EMT_PrimitiveTriangle)
	{
		NewMesh = std::shared_ptr<MeshBase>( new MeshTriangle());
	}

	mAllocatorGPU.AllocateStaticMesh(NewMesh.get());
	mRenderer->AddMeshToDraw(NewMesh);
	// Allocate memory for mesh
	// Create Mesh
	// Return Mesh
	return NewMesh;
}