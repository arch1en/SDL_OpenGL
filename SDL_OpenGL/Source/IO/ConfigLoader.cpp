#include "ConfigLoader.h"

#include "Paths.h"
#include "Helpers.h"

#include <iostream>

// TODO_1 : This will definitely need some optimization.
void ConfigLoader::LoadConfigData(const std::string& InFileName, const std::string& InCategory, std::map<std::string, std::string>& OutResult)
{
	std::fstream FStream;

	std::string FilePath(Paths::GetInstance().GetPathConfig() + InFileName + ".ini");

	FStream.open(FilePath);

	bool FoundCategory = false;

	if (FStream.is_open() == true)
	{
		while (FStream.eof() != true)
		{
			const size_t LineDataSize = 256;
			char LineData[LineDataSize];

			FStream.getline(LineData, LineDataSize);
			if (LineData[0] == '#')
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
	}
	else
	{
		Log(DebugType::EDT_Error, "Config file \"%s\" could not be open.", InFileName.c_str());
	}
}