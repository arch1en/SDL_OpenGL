////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Input Layer
//  @author     : Artur Ostrowski
//  @usage      : Keeps data of key commands and broadcasts events to interesants (InputComponents).
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include <string>
#include <map>

class InputComponent;

struct MouseData
{
	int	MouseX;
	int MouseY;
	int DirectionX;
	int DirectionY;
};

struct KeyData
{
	char Key;
	std::string Command;
};

class InputLayer
{
public:
	InputLayer(const std::string& InLayerCategory);
	InputLayer(const std::string& InLayerCategory, std::map<char, std::string> InKeyMap);
	virtual ~InputLayer() {}

	void BindComponent(InputComponent* aComponent);
	void UnbindComponent(InputComponent* aComponent);

	std::string TranslateInputKey(const SDL_Keycode& aInputKey);
	void PrepareAndBroadcastIntermittentCommand(const SDL_Keycode& aInputKey);
	void BroadcastIntermittentCommand(const KeyData& aKeyData);
	void BroadcastContinuousCommand(const KeyData& aKeyData);
	void BroadcastMouseMotionCommand(int& aLastMouseX, int& aLastMouseY);

	std::string FindCommandByKey(const char& aKey);
	const std::string GetCategory() { return mCategory; }

	bool CanBroadcastCommand(const std::string& aCommand);

	inline std::map<char, std::string>&	GetKeyMap() { return mKeyMap; }

	const ArrayIndex IsComponentBound(InputComponent* aComponent);
protected:

	std::string mCategory;

	std::map<char, std::string>	mKeyMap;

	std::vector<InputComponent*> mBoundComponents;
};