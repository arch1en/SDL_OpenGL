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

namespace an
{
	enum ETextureWrappingMode
	{
		Repeat = GL_REPEAT,
		MirroredRepeat = GL_MIRRORED_REPEAT,
		ClampToEdge = GL_CLAMP_TO_EDGE,
		ClampToBorder = GL_CLAMP_TO_BORDER
	};

	enum ETextureFilteringMode
	{
		Nearest = GL_NEAREST,
		Linear = GL_LINEAR
	};

	enum ETextureMipmappingMode
	{
		NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
		NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
		LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
		LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
	};

	enum ETextureType
	{
		Albedo,
		Diffuse,
		Specular,
		Normal
	};

	struct STextureData
	{
		std::vector<GLfloat> Coordinates;
		std::vector<GLfloat> BorderColor;

		GLenum Wrap_S;
		GLenum Wrap_T;
		GLenum Filter_Min;
		GLenum Filter_Mag;

		STextureData() {}
		STextureData(
			ETextureWrappingMode aWrap_S,
			ETextureWrappingMode aWrap_T,
			ETextureFilteringMode aFilter_Min,
			ETextureFilteringMode aFilter_Mag);

		STextureData(const STextureData &aData);
	};

	class CTexture
	{
	public:

		CTexture();
		void Initiate(std::string aPath, STextureData aTextureData);
		const STextureData* GetData() const;

	private:

		GLuint			mTexture;
		STextureData		mData;

		void GenerateTexture(std::string aPath);
		int LoadTextureImage(std::string path, int& aOutWidth, int& aOutHeight, int& aOutNrChannels, unsigned char*& aOutImageData);

	};
}

