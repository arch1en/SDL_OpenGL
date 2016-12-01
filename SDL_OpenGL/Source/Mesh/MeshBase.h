////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Mesh Base
//  @author     : Artur Ostrowski
//  @usage      : Base class for all meshes.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "../stdafx.h"
#include <memory>

struct PolygonData
{
	std::vector<GLfloat>	Indices;
	GLint		NumIndices;
	std::vector<GLfloat>	Color;
	GLint		NumColor;
	std::vector<GLint>		Elements;
	GLint		NumElements;
};

class MeshBase
{

public:
	virtual ~MeshBase();

	PolygonData mPolygonData;

protected:

	const char*			MeshTag;

private:

	std::shared_ptr<GLuint> mRefVAO;
	std::shared_ptr<GLuint> mRefVBO;
	std::shared_ptr<GLuint> mRefEBO;

};