////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Mesh Cube
//  @author     : Artur Ostrowski
//  @usage      : Hardcoded cube mesh for testing purposes.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "MeshCube.h"

MeshCube::MeshCube()
{
	mPolygonData.NumIndices = 3 * 8;

	mPolygonData.Indices = {	-0.5f, -0.5f,  0.5f,
								 0.5f, -0.5f,  0.5f,
								 0.5f,  0.5f,  0.5f,
								-0.5f,  0.5f,  0.5f,
								-0.5f, -0.5f, -0.5f,
								 0.5f, -0.5f, -0.5f,
								 0.5f,  0.5f, -0.5f,
								-0.5f,  0.5f, -0.5f, };

	mPolygonData.NumColor = 3 * 8;

	mPolygonData.Color = {	1.0f, 0.0f, 0.0f,
							1.0f, 0.5f, 1.0f,
							1.0f, 0.0f, 0.5f,
							1.0f, 0.5f, 0.0f,
							0.5f, 1.0f, 0.5f,
							0.5f, 1.0f, 1.0f,
							0.0f, 1.0f, 0.5f,
							0.0f, 1.0f, 1.0f };

	mPolygonData.Elements = {	0, 1, 2, 
							//	1, 2, 3,
							//	0, 4, 5,

		};

	mPolygonData.NumElements = 3 * 12;

	mPolygonData.NumTextureCoordinates = 0;

	mPolygonData.TextureCoordinates = {
		0.0f, 0.0f,
		0.5f, 1.0f,
		1.0f, 0.0f,
	};

	MeshTag = "PrimitiveCube";

}