////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Input Layer
//  @author     : Artur Ostrowski
//  @usage      : Keeps data of key commands and broadcasts events to interesants (InputComponents).
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "InputLayer.h"

#include <algorithm>

#include "Components/InputComponent.h"

InputLayer::InputLayer(const std::string& aLayerCategory)
{
	mCategory = aLayerCategory;
}

InputLayer::InputLayer(const std::string& aLayerCategory, std::map<std::string, std::string> aKeyMap)
{
	mCategory = aLayerCategory;
	mKeyMap = aKeyMap;
}

void InputLayer::BindComponent(InputComponent* aComponent)
{
	const int ComponentPlaceInArray{ IsComponentBound(aComponent) };

	if (ComponentPlaceInArray >= 0)
	{
		Log(DebugType::EDT_Warning, "Component already bound !");
		return;
	}

	mBoundComponents.push_back(aComponent);

}

void InputLayer::UnbindComponent(InputComponent* aComponent)
{
	const int ComponentPlaceInArray{ IsComponentBound(aComponent) };

	if (ComponentPlaceInArray == -1)
	{
		Log(DebugType::EDT_Warning, "Cannot unbind component. Component not present in array.");
		return;
	}
	
	mBoundComponents.erase(mBoundComponents.begin() + ComponentPlaceInArray);
}

const ArrayIndex InputLayer::IsComponentBound(InputComponent* aComponent)
{
	auto& Result = std::find(mBoundComponents.begin(), mBoundComponents.end(), aComponent);

	if (Result != mBoundComponents.end())
	{
		return Result - mBoundComponents.begin();
	}

	return -1;
}

std::string InputLayer::TranslateInputKey(const SDL_Keycode& aInputKey)
{
	std::string Char;
	Char.push_back(static_cast<char>(aInputKey));

	return FindCommandByKey(Char);
}

std::string InputLayer::FindCommandByKey(const std::string& aKey)
{
	auto Result = mKeyMap.find(aKey);

	if (Result != mKeyMap.end())
	{
		return mKeyMap.at(aKey);
	}

	Log(DebugType::EDT_Warning, "Command not found in \"%s\" layer category.", mCategory.c_str());
	return std::string();
}

void InputLayer::BroadcastCommand(const SDL_Keycode& aInputKey)
{
	const std::string TranslatedKey = TranslateInputKey(aInputKey);
	if (CanBroadcastCommand(TranslatedKey) == true)
	{
		BroadcastCommand(TranslatedKey);
	}
}

void InputLayer::BroadcastCommand(std::string aCommand)
{
	for (auto& Component : mBoundComponents)
	{
		for (auto& Delegate : Component->GetDelegates())
		{
			Delegate(aCommand);
		}
	}
}

bool InputLayer::CanBroadcastCommand(const std::string& aCommand)
{
	return aCommand.size() > 0;
}