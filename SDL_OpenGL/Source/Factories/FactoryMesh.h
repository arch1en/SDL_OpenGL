#pragma once

#include "../stdafx.h"

#include <memory>

#include "Allocators/AllocatorGPU.h"
#include "Renderers/Renderer.h"

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
	FactoryMesh(std::shared_ptr<Renderer> InRenderer);
	~FactoryMesh() {}

	void Initialize();

	std::shared_ptr<MeshBase> NewMesh(MeshType InMeshType);

private:

	AllocatorGPU				mAllocatorGPU;
	std::shared_ptr<Renderer>	mRenderer;

};