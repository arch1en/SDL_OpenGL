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

InputLayer::InputLayer(const std::string& aLayerCategory, std::map<char, std::string> aKeyMap)
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
	return FindCommandByKey(static_cast<char>(aInputKey));
}

std::string InputLayer::FindCommandByKey(const char& aKey)
{
	auto Result = mKeyMap.find(aKey);

	if (Result != mKeyMap.end())
	{
		return mKeyMap.at(aKey);
	}

	Log(DebugType::EDT_Warning, "Command not found in \"%s\" layer category.", mCategory.c_str());
	return std::string();
}

void InputLayer::PrepareAndBroadcastIntermittentCommand(const SDL_Keycode& aInputKey)
{
	const std::string TranslatedKey = TranslateInputKey(aInputKey);
	if (CanBroadcastCommand(TranslatedKey) == true)
	{
		KeyData Data;

		Data.Key = static_cast<char>(aInputKey);
		Data.Command = TranslatedKey;

		BroadcastIntermittentCommand(Data);
	}
}

void InputLayer::BroadcastIntermittentCommand(const KeyData& aKeyData)
{
	for (auto& Component : mBoundComponents)
	{
		for (auto& Delegate : Component->GetIntermittentDelegates())
		{
			Delegate(aKeyData);
		}
	}
}

void InputLayer::BroadcastContinuousCommand(const KeyData& aKeyData)
{
	for (auto& Component : mBoundComponents)
	{
		for (auto& Delegate : Component->GetContinuousDelegates())
		{
			Delegate(aKeyData);
		}
	}
}

void InputLayer::BroadcastMouseMotionCommand(int& aLastMouseX, int& aLastMouseY)
{
	int MouseX = 0;
	int MouseY = 0;

	SDL_GetMouseState(&MouseX, &MouseY);

	MouseData Data{ MouseX, MouseY, MouseX - aLastMouseX, MouseY - aLastMouseY };

	for (auto& Component : mBoundComponents)
	{
		Component->mLastMousePosition = glm::vec2{ aLastMouseX, aLastMouseY };

		for (auto& Delegate : Component->GetMouseMotionDelegates())
		{

			Delegate(Data);
		}
	}

	aLastMouseX = MouseX;
	aLastMouseY = MouseY;
}

bool InputLayer::CanBroadcastCommand(const std::string& aCommand)
{
	return aCommand.size() > 0;
}