#include "FactoryTexture.h"	

#include "Rendering\Texture.h"
#include "Helpers.h"
#include <SDL_image.h>
#include <algorithm>

const unsigned char* FactoryTexture::LoadImageFromFile(const char* aFilePath)
{
	int InitFlags = 0;
	std::string Extension;
	Extension = an::GetFileExtension(aFilePath);

	if (Extension.size() <= 0)
	{
		Log(DebugType::EDT_Error, "Image loading failed, file extension not found.");
		return nullptr;
	}

	// Convert extension to lowercase, so comparing will be possible.
	std::transform(Extension.begin(), Extension.end(), Extension.begin(), ::tolower);

	if (Extension.compare("jpg") == 0)
	{
		InitFlags |= IMG_INIT_JPG;
	}
	if (Extension.compare("png") == 0)
	{
		InitFlags |= IMG_INIT_PNG;
	}
	if (Extension.compare("tif") == 0)
	{
		InitFlags |= IMG_INIT_TIF;
	}

	// All filetypes recognised by SDL (case doesnt matter ?)
	//"BMP"
	//	"CUR"
	//	"GIF"
	//	"ICO"
	//	"JPG"
	//	"LBM"
	//	"PCX"
	//	"PNG"
	//	"PNM"
	//	"TGA"
	//	"TIF"
	//	"XCF"
	//	"XPM"
	//	"XV"

	if (InitFlags == 0)
	{
		Log(DebugType::EDT_Error, "Image loading failed, file extension not recognised.");
		return nullptr;
	}

	// TODO : Loading images using SDL is super heavy, we need to find a way to load images all by once.
	int InitResult = IMG_Init(InitFlags);

	if (InitResult & InitFlags != InitFlags)
	{
		Log(DebugType::EDT_Error, "Failed to initialize \"%s\" image extension modules", Extension);
		Log(DebugType::EDT_Notice, "%s", IMG_GetError());
		return nullptr;
	}

	SDL_Surface* NewImageSurface = IMG_Load(aFilePath);

	// Unload resources after loading images.
	IMG_Quit();

	
}

void FactoryTexture::CreateTexture(TextureData aData)
{
	std::unique_ptr<Texture> NewTexture = std::make_unique<Texture>();

	GLuint NewTextureID;

	glGenTextures(1, &NewTextureID);
	glBindTexture(GL_TEXTURE_2D, NewTextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, aData.Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, aData.Wrap_T);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, aData.Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, aData.Filter_Mag);

}