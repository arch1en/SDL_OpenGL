#include "Sampler.h"
#include "stdafx.h"

void Sampler::LoadTextureImage(std::string path)
{
	int width, height;
	unsigned char* image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D			// Function starts to load image from coord (0,0). Remember this.
	(	
		GL_TEXTURE_2D,		// Texture target
		0,					// Level of Detail
		GL_RGB,				// Internal pixel format (format in which pixels will be stored in GPU)
		width,				// Width of an image
		height,				// Height of an image
		0,					// Dunno, but always 0
		GL_RGB,				// Format of the pixels in the array that will be loaded
		GL_UNSIGNED_BYTE,	// Datatype of the coordinates in the array that will be loaded
		image			// image array
	);
	SOIL_free_image_data(image);
}