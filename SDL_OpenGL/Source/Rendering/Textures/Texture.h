////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Texture
//  @author     : Artur Ostrowski
//  @usage      : Keeps data of a texture.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

enum TextureWrappingMode
{
	Repeat			= GL_REPEAT,
	MirroredRepeat	= GL_MIRRORED_REPEAT,
	ClampToEdge		= GL_CLAMP_TO_EDGE,
	ClampToBorder	= GL_CLAMP_TO_BORDER
};

enum TextureFilteringMode
{
	Nearest			= GL_NEAREST,
	Linear			= GL_LINEAR
};

enum TextureMipmappingMode
{
	NearestMipmapNearest	= GL_NEAREST_MIPMAP_NEAREST,
	NearestMipmapLinear		= GL_NEAREST_MIPMAP_LINEAR,
	LinearMipmapNearest		= GL_LINEAR_MIPMAP_NEAREST,
	LinearMipmapLinear		= GL_LINEAR_MIPMAP_LINEAR
};

enum TextureType
{
	Albedo,
	Diffuse,
	Specular,
	Normal
};

struct TextureData
{
	GLenum Wrap_S;
	GLenum Wrap_T;
	GLenum Filter_Min;
	GLenum Filter_Mag;

	TextureData(TextureData &aData)
	{
		Wrap_S =		aData.Wrap_S;
		Wrap_T =		aData.Wrap_T;
		Filter_Min =	aData.Filter_Min;
		Filter_Mag =	aData.Filter_Mag;
	}
};

class Texture
{
public:
	Texture(TextureWrappingMode aWrapping, TextureFilteringMode aFiltering);
		: mTextureCoordinates { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f }
		, mBorderColor{ 0.0f, 0.0f, 0.0f, 1.0f }
	{}

private:

	GLuint			mTexture;
	TextureData		mData;

	GLfloat mTextureCoordinates[];
	GLfloat mBorderColor[];


};