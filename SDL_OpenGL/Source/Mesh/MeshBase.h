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