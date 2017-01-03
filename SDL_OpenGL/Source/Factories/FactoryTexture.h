#pragma once

#include "stdafx.h"

class Texture;
class TextureData;

class FactoryTexture
{
public:

	FactoryTexture() {}
	~FactoryTexture() {}

	const unsigned char* LoadImageFromFile(const char* aFilePath);
	void CreateTexture(TextureData aData);

private:

	std::vector<std::unique_ptr<Texture>> mTextures;

};