#pragma once

#include "stdafx.h"

#include <map>

class ConfigLoader
{
public:
	void LoadConfigData(const std::string& InFileName, const std::string& InCategory, std::map<std::string, std::string>& OutResult);
	
	static inline ConfigLoader& GetInstance()
	{
		static ConfigLoader Instance;
		return Instance;
	}

	void ReloadConfigData(); // TODO : Implement

};