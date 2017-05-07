////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Handles creation of new meshes onto the scene.
//  @version    : 1.0.0
//	@tags		: [Static]
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include <memory>

#include "Allocators/AllocatorGPU.h"
#include "Rendering/Renderer.h"

class MeshBase;

enum class MeshType : uint8_t
{
	EMT_PrimitiveTriangle,
	EMT_PrimitiveCube,
	EMT_PrimitivePlane
};

class FactoryMesh
{
public:
	FactoryMesh();
	~FactoryMesh() {}

	void Initialize();
	static FactoryMesh* GetInstance();

	void SetRenderer(std::shared_ptr<Renderer> aRenderer);
	void SetAllocatorGPU(std::shared_ptr<AllocatorGPU> aAllocator);

	std::shared_ptr<MeshBase> NewMesh(std::shared_ptr<MeshComponent> aComponent, std::string InMeshType);
	void DestroyMesh(std::shared_ptr<MeshComponent> aMesh);

private:

	std::shared_ptr<Renderer>		mRenderer;
	std::shared_ptr<AllocatorGPU>	mAllocatorGPU;


	std::vector<std::shared_ptr<MeshComponent>> mCreatedMeshes;

};