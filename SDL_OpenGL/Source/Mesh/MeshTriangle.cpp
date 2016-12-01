////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Mesh Triangle
//  @author     : Artur Ostrowski
//  @usage      : Hardcoded triangle mesh for testing purposes.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "MeshTriangle.h"

MeshTriangle::MeshTriangle()
{
	mPolygonData.NumIndices = 3 * 3;

	mPolygonData.Indices =  {	
		-1.0f, -1.0f, +0.0f,
		+0.0f, +1.0f, +0.0f,
		+1.0f, -1.0f, +0.0f, };

	mPolygonData.NumColor = 3 * 3;

	mPolygonData.Color = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f, };

	mPolygonData.NumElements = 3;

	mPolygonData.Elements = { 0, 1, 2 };

	MeshTag = "Primitive2DTriangle";
}
