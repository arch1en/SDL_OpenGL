#pragma once

#include "stdafx.h"

#include <string>
#include <map>

#include "Interfaces\IObserver.h"

class InputLayer : public ISubject
{
public:
	InputLayer(std::string InName, std::string InLayerName);
	InputLayer(std::string InName, std::string InLayerName, std::map<std::string, std::string> InKeyMap);
	virtual ~InputLayer() {}

protected:

	std::string mName;
	std::string mLayerName;

	std::map<std::string, std::string>	mKeyMap;
};