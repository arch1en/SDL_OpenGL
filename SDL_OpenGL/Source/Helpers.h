#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace an
{
	void Split(const char * InSentence, char InDelimiter, std::vector<std::string> & OutTokens)
	{
		std::stringstream SStream;
		SStream.str(InSentence);

		std::string Item;
		while (std::getline(SStream, Item, InDelimiter))
		{
			OutTokens.push_back(Item);
		}
	}
}

