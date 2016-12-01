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

	void AllocateStaticMesh(MeshBase* _Mesh);

private:

	std::vector<GLuint>		mVAOs;
	std::vector<GLuint>		mVBOs;
	std::vector<GLuint>		mEBOs;

};