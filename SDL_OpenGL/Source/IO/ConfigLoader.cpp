////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Singleton responsible for handling config file loading and reloading (in the future).
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "ConfigLoader.h"

#include "Paths.h"
#include "Helpers.h"

#include <iostream>
#include <algorithm>

// TODO_1 : This will definitely need some optimization.
int ConfigLoader::LoadConfigData(const std::string& InFileName, const std::string& InCategory, std::map<std::string, std::string>& OutResult)
{
	std::fstream FStream;

	std::string FilePath(an::Paths::GetInstance().GetPathConfig() + InFileName + ".ini");

	FStream.open(FilePath);

	bool FoundCategory = false;

	if (FStream.is_open() == true)
	{
		while (FStream.eof() != true)
		{
			const size_t LineDataSize = 256;
			char LineData[LineDataSize];

			FStream.getline(LineData, LineDataSize);
			if (LineData[0] == '#' || LineData[0] == '\0')
			{
				continue;
			}

			if (FoundCategory == true)
			{

				if (LineData[0] == '[')
				{
					break;
				}

				std::vector<std::string> Tokens;

				an::Split(LineData, '=', Tokens);

				if (Tokens.size() != 2)
				{
					Log(DebugType::EDT_Error, "%s file parsing error. Check if file data is valid.", InFileName.c_str());
					return 1;
				}

				OutResult.insert(std::pair<std::string, std::string>(Tokens[0], Tokens[1]));
				
			}

			if (LineData[0] == '[')
			{
				const size_t CategoryDataSize = 256;
				char CategoryData[CategoryDataSize];
				sprintf_s(CategoryData, "[%s]", InCategory.c_str());
				if (strcmp(LineData, CategoryData) == 0)
				{
					FoundCategory = true;
				}
			}
		}

		if (FoundCategory == false)
		{
			Log(DebugType::EDT_Warning, "Category \"%s\" in property file \"%s\" was not found.", InCategory.c_str(), InFileName.c_str());
			return 2;
		}

	}
	else
	{
		Log(DebugType::EDT_Error, "Config file \"%s\" could not be open.", InFileName.c_str());
		return 3;
	}

	return 0;
}

// THIS IS EXACTLY THE SAME LIKE LOADCONFIGDATA, CHANGE IT !
int ConfigLoader::LoadInputData(const std::string& InFileName, const std::string& InCategory, std::map<char, std::string>& OutResult)
{
	std::fstream FStream;

	std::string FilePath(an::Paths::GetInstance().GetPathConfig() + InFileName + ".ini");

	FStream.open(FilePath);

	bool FoundCategory = false;

	if (FStream.is_open() == true)
	{
		while (FStream.eof() != true)
		{
			const size_t LineDataSize = 256;
			char LineData[LineDataSize];

			FStream.getline(LineData, LineDataSize);
			if (LineData[0] == '#' || LineData[0] == '\0')
			{
				continue;
			}

			if (FoundCategory == true)
			{

				if (LineData[0] == '[')
				{
					break;
				}

				std::vector<std::string> Tokens;

				an::Split(LineData, '=', Tokens);

				if (Tokens.size() != 2)
				{
					Log(DebugType::EDT_Error, "%s file parsing error. Check if file data is valid.", InFileName.c_str());
					return 1;
				}

				std::transform(Tokens[1].begin(), Tokens[1].end(), Tokens[1].begin(), ::tolower);
				if (Tokens[1].size() > 1)
				{
					char Key = 0;
					an::TranslateInputKeyToSDLKeycode(Tokens[1], Key);
					Tokens[1].clear();
					Tokens[1] = Key;
				}
				OutResult.insert(std::pair<char, std::string>(*Tokens[1].c_str(), Tokens[0]));

			}

			if (LineData[0] == '[')
			{
				const size_t CategoryDataSize = 256;
				char CategoryData[CategoryDataSize];
				sprintf_s(CategoryData, "[%s]", InCategory.c_str());
				if (strcmp(LineData, CategoryData) == 0)
				{
					FoundCategory = true;
				}
			}
		}

		if (FoundCategory == false)
		{
			Log(DebugType::EDT_Warning, "Category \"%s\" in property file \"%s\" was not found.", InCategory.c_str(), InFileName.c_str());
			return 2;
		}

	}
	else
	{
		Log(DebugType::EDT_Error, "Config file \"%s\" could not be open.", InFileName.c_str());
		return 3;
	}

	return 0;
}