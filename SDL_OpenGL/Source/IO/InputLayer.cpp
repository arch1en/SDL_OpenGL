#include "InputLayer.h"

InputLayer::InputLayer(std::string InName, std::string InLayerName)
{
	mName = InName;
	mLayerName = InLayerName;
}

InputLayer::InputLayer(std::string InName, std::string InLayerName, std::map<std::string, std::string> InKeyMap)
{
	mName = InName;
	mLayerName = InLayerName;
	mKeyMap = InKeyMap;
}
