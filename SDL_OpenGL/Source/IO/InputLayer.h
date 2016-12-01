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

class InputLayer
{
public:
	InputLayer(const std::string& InLayerCategory);
	InputLayer(const std::string& InLayerCategory, std::map<std::string, std::string> InKeyMap);
	virtual ~InputLayer() {}

	void BindComponent(InputComponent* aComponent);
	void UnbindComponent(InputComponent* aComponent);

	std::string TranslateInputKey(const SDL_Keycode& aInputKey);
	void BroadcastCommand(const SDL_Keycode& aInputKey);
	void BroadcastCommand(std::string aCommand);

	std::string FindCommandByKey(const std::string& aKey);
	const std::string GetCategory() { return mCategory; }

	bool CanBroadcastCommand(const std::string& aCommand);

	const ArrayIndex IsComponentBound(InputComponent* aComponent);
protected:

	std::string mCategory;

	std::map<std::string, std::string>	mKeyMap;

	std::vector<InputComponent*> mBoundComponents;
};