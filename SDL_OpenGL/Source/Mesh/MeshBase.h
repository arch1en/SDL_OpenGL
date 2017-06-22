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
	std::vector<GLuint>	Elements;
	GLint		NumElements;
	std::vector<GLfloat>	TextureCoordinates;
	GLint		NumTextureCoordinates;

	PolygonData()
		: NumIndices{0}
		, NumColor{0}
		, NumElements{0}
		, NumTextureCoordinates{0}
	{}

};

class MeshBase
{

public:
	virtual ~MeshBase() {}

	PolygonData mPolygonData;

protected:

	const char*			MeshTag;

private:

	std::shared_ptr<GLuint> mRefVAO;
	std::shared_ptr<GLuint> mRefVBO;
	std::shared_ptr<GLuint> mRefEBO;
	std::shared_ptr<GLuint> mRefTBO;

};