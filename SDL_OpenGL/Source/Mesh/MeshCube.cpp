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
#include "IO/Paths.h"

MeshCube::MeshCube()
{
	mPolygonData.Indices = {	   
		// front
		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0, };

	mPolygonData.Color = {	    
		// front colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
		// back colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0, };

	mPolygonData.Elements = {			
		// front
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3,

		};

	//mPolygonData.TextureCoordinates = {
	//	1.0f, 1.0f,
	//	1.0f, 0.0f,
	//	0.0f, 0.0f,
	//	0.0f, 1.0f
	//};


	an::STextureData Data(
		an::ETextureWrappingMode::MirroredRepeat,
		an::ETextureWrappingMode::MirroredRepeat,
		an::ETextureFilteringMode::Nearest,
		an::ETextureFilteringMode::Linear);

	mTexture = an::CTexture();
	mTexture.Initiate(an::Paths::GetInstance().GetPathAssets() + "Textures\\cheshire.jpg", Data);

	MeshTag = "PrimitiveCube";

}