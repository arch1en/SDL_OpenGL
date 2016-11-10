////////////////////////////////////////
//
//  @project    : Game Engine
//  @author     : Artur Ostrowski
//  @usage      : This class is responsible for allocating memory to GPU. Everything that is suppose to be deallocated, has to be deallocated through this class !
//  @version    : 1.0.0
//
////////////////////////////////////////

#include "AllocatorGPU.h"

#include "Debuggers/Debugger.h"

AllocatorGPU::~AllocatorGPU()
{
	glDeleteBuffers(mVBOs.size(), &mVBOs[0]);
	glDeleteBuffers(mEBOs.size(), &mEBOs[0]);
	glDeleteVertexArrays(mVAOs.size(), &mVAOs[0]);
	Log(DebugType::EDT_Notice, "AllocatorGPU::Dtor - All buffers are destroyed.");
}

void AllocatorGPU::Initialize()
{
	GLuint NewVAO;
	glGenVertexArrays(1, &NewVAO);
	glBindVertexArray(NewVAO);
	mVAOs.push_back(NewVAO);
}

void AllocatorGPU::AllocateStaticMesh(MeshBase* Mesh)
{
	GLuint NewVBO;
	GLuint NewEBO;

	GLsizeiptr IndicesBufferSize = sizeof(Mesh->mPolygonData.Indices[0]) * Mesh->mPolygonData.NumIndices;
	GLsizeiptr ColorBufferSize = sizeof(Mesh->mPolygonData.Color[0]) * Mesh->mPolygonData.NumColor;
	GLsizeiptr ElementBufferSize = sizeof(Mesh->mPolygonData.Elements[0]) * Mesh->mPolygonData.NumElements;

	GLsizeiptr CombinedBufferSize = IndicesBufferSize + ColorBufferSize;

	if (IndicesBufferSize == 0 || ColorBufferSize == 0 || ElementBufferSize == 0)
	{
		Log(DebugType::EDT_Error, "Buffers are empty.");
	}

	glGenBuffers(1, &NewVBO);
	glGenBuffers(1, &NewEBO);

	glBindBuffer(GL_ARRAY_BUFFER, NewVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NewEBO);

	GLintptr Offset = 0;

	glBufferData(GL_ARRAY_BUFFER, CombinedBufferSize, 0, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, Offset, IndicesBufferSize, &Mesh->mPolygonData.Indices[0]);
		Offset += IndicesBufferSize;
		glBufferSubData(GL_ARRAY_BUFFER, Offset, ColorBufferSize, &Mesh->mPolygonData.Color[0]);

	GLsizei Stride = 6 * sizeof(GLfloat);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Stride, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Stride, (GLvoid*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ElementBufferSize, &Mesh->mPolygonData.Elements[0], GL_STATIC_DRAW);

	mVBOs.push_back(NewVBO);
	mEBOs.push_back(NewEBO);
}