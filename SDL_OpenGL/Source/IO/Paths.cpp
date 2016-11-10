#include "Paths.h"

Paths::Paths()
{
	std::string Path = SDL_GetBasePath();
	
	std::size_t Found = Path.rfind("\\", Path.length() - 2);
	if (Found != std::string::npos)
	{
		Path.erase(Found + 1, Path.length());
		Path.append("SDL_OpenGL\\");
	}
	else
	{
		Log(DebugType::EDT_Error, "Failed to trim the basic path string. Investigate !");
	}

	PathAssets = Path + "Assets\\";
	PathConfig = Path + "Config\\";
	PathSourceCode = Path + "SourceCode\\";
	PathLogs = Path + "Logs\\";
}

