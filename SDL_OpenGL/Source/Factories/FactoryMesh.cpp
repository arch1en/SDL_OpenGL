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
	std::shared_ptr<MeshBase> Mesh(nullptr);

	if (InMeshType == MeshType::EMT_PrimitiveTriangle)
	{
		Mesh = std::make_shared<MeshTriangle>();
	}

	bool MeshAllocationResult = mAllocatorGPU.AllocateStaticMesh(Mesh.get());
	if (MeshAllocationResult == false)
	{
		Log(DebugType::EDT_Error, "Mesh creation failed !");
		return nullptr;
	}

	mRenderer->AddMeshToDraw(Mesh);

	// Allocate memory for mesh
	// Create Mesh
	// Return Mesh
	mCreatedMeshes.push_back(Mesh);

	return Mesh;
}

void FactoryMesh::DestroyMesh(std::shared_ptr<MeshBase> aMesh)
{
	if (mCreatedMeshes.size() == 0) return;

	for (auto& iter = mCreatedMeshes.begin(); iter != mCreatedMeshes.end(); iter++)
	{
		// TODO : Test if this works.
		if (*iter == aMesh)
		{
			iter->reset();
			mCreatedMeshes.erase(iter);
		}
	}
}