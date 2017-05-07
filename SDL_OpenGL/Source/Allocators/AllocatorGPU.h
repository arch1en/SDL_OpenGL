////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : This class is responsible for allocating memory to GPU. Everything that is suppose to be deallocated, has to be deallocated through this class !
//  @version    : 1.0.0
//
////////////////////////////////////////

#pragma once

#include "../stdafx.h"
#include "Mesh/MeshBase.h"
#include <vector>

struct MeshData
{
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};

class AllocatorGPU
{
public:
	AllocatorGPU() {}
	void Initialize();
	~AllocatorGPU();

	bool AllocateStaticMesh(MeshBase* aMesh);
	void AllocateTextureData(MeshBase* aMesh);

	GLuint GetActiveVAO() const;

private:

	GLuint mActiveVAO;

	std::vector<GLuint>		mVAOs;	// Vertex Array Object
	std::vector<GLuint>		mVBOs;	// Vertex Buffer Object
	std::vector<GLuint>		mTBOs;	// Texture Buffer Object
	std::vector<GLuint>		mEBOs;	// Element Buffer OBject

	void SetActiveVAO(GLuint aValue);
};