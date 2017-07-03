#include "Texture.h"

#include <stb_image.h>

an::STextureData::STextureData
	(
	ETextureWrappingMode aWrap_S,
	ETextureWrappingMode aWrap_T,
	ETextureFilteringMode aFilter_Min,
	ETextureFilteringMode aFilter_Mag
	)
{
	Wrap_S = aWrap_S;
	Wrap_T = aWrap_T;
	Filter_Min = aFilter_Min;
	Filter_Mag = aFilter_Mag;
}

an::STextureData::STextureData(const STextureData &aData)
{
	Wrap_S = aData.Wrap_S;
	Wrap_T = aData.Wrap_T;
	Filter_Min = aData.Filter_Min;
	Filter_Mag = aData.Filter_Mag;
	Coordinates = aData.Coordinates;
	BorderColor = aData.BorderColor;
}

an::CTexture::CTexture(){}

void an::CTexture::Initiate(std::string aPath, STextureData aTextureData)
{
	mData = aTextureData;
	GenerateTexture(aPath);
}

void an::CTexture::GenerateTexture(std::string aPath)
{
	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	int Width, Height, NrChannels;
	unsigned char* Data = nullptr;

	if (LoadTextureImage(aPath, Width, Height, NrChannels, Data) == 0)
	{
		GLenum Target = GL_TEXTURE_2D;

		glTexParameteri(Target, GL_TEXTURE_WRAP_S, mData.Wrap_S);
		glTexParameteri(Target, GL_TEXTURE_WRAP_T, mData.Wrap_T);
		glTexParameteri(Target, GL_TEXTURE_MIN_FILTER, mData.Filter_Min);
		glTexParameteri(Target, GL_TEXTURE_MAG_FILTER, mData.Filter_Mag);

		glTexImage2D			// Function starts to load image from coord (0,0). Remember this.
		(
			GL_TEXTURE_2D,		// Texture target
			0,					// Level of Detail
			GL_RGB,				// Internal pixel format (format in which pixels will be stored in GPU)
			Width,				// Width of an image
			Height,				// Height of an image
			0,					// Dunno, but always 0
			GL_RGB,				// Format of the pixels in the array that will be loaded
			GL_UNSIGNED_BYTE,	// Datatype of the coordinates in the array that will be loaded
			(void*)Data				// image array
		);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(Data);
	}
	else
	{
		Log(DebugType::EDT_Warning, "");
	}

}

int an::CTexture::LoadTextureImage(std::string path, int& aOutWidth, int& aOutHeight, int& aOutNrChannels, unsigned char*& aOutImageData)
{
	std::ifstream file(path);

	if (!file.good())
	{
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Sampler : cannot open file");
		file.close();
		return 1;
	}

	file.close();

	aOutImageData = stbi_load(path.c_str(), &aOutWidth, &aOutHeight, &aOutNrChannels, 0);

	if (aOutImageData[0] == 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Sampler : image not loaded, check file path");
		return 2;
	}

	return 0;
}

const  an::STextureData*  an::CTexture::GetData() const
{
	return &mData;
}