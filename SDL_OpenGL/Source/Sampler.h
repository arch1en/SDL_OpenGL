
#include <SOIL.h>
#include <string>
#include <fstream>
#include "stdafx.h"

namespace Sampler
{
	static bool LoadTextureImage(std::string path, int& aOutWidth, int& aOutHeight, unsigned char*& aOutImageData)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Sampler : cannot open file");
			file.close();
			return false;
		}

		file.close();

		unsigned char* image = SOIL_load_image(path.c_str(), &aOutWidth, &aOutHeight, 0, SOIL_LOAD_RGB);

		if (image[0] == 0)
		{
			SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Sampler : image not loaded, check file path");
			return false;
		}
			
		glTexImage2D			// Function starts to load image from coord (0,0). Remember this.
			(
			GL_TEXTURE_2D,		// Texture target
			0,					// Level of Detail
			GL_RGBA,				// Internal pixel format (format in which pixels will be stored in GPU)
				aOutWidth,				// Width of an image
				aOutHeight,				// Height of an image
			0,					// Dunno, but always 0
			GL_RGBA,				// Format of the pixels in the array that will be loaded
			GL_UNSIGNED_BYTE,	// Datatype of the coordinates in the array that will be loaded
			image				// image array
			);
		SOIL_free_image_data(image);

		return true;
	}
}
