////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Singleton responsible for handling config file loading and reloading (in the future).
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include <map>

class ConfigLoader
{
public:
	int LoadConfigData(const std::string& InFileName, const std::string& InCategory, std::map<std::string, std::string>& OutResult);
	int LoadInputData(const std::string& InFileName, const std::string& InCategory, std::map<char, std::string>& OutResult);
	
	static inline ConfigLoader& GetInstance()
	{
		static ConfigLoader Instance;
		return Instance;
	}

	// TODO : Implement
	void ReloadConfigData(); 
private:

	// TODO : Implement
	void LoadDataFromFile(const std::string& InFileName, const std::string& InCategory, std::map<std::string, std::string>& OutResult);
};