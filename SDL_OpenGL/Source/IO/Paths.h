#pragma once

#include "stdafx.h"

class Paths
{

public:

	Paths();
	Paths(const Paths&) = delete;
	void operator=(const Paths&) = delete;

	static Paths& GetInstance() 
	{
		static Paths Instance;
		return Instance; 
	}

	inline std::string GetPathAssets() const { return PathAssets; }
	inline std::string GetPathConfig() const { return PathConfig; }
	inline std::string GetPathSourceCode() const { return PathSourceCode; }
	inline std::string GetPathLogs() const { return PathLogs; }

private:

	std::string PathAssets;
	std::string PathConfig;
	std::string PathSourceCode;
	std::string PathLogs;

};

