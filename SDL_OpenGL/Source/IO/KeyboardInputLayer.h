#pragma once

#include "stdafx.h"
#include <boost/bimap.hpp>

#include "InputLayer.h"

class KeyboardInputLayer : public InputLayer
{
public:
	KeyboardInputLayer(std::string InName, std::string InLayerName);
	KeyboardInputLayer(std::string InName, std::string InLayerName, std::map<std::string, std::string> InKeyMap);

	// TODO : Decide on how to read input from layers.
	void KeyDown(const SDL_Keycode& InKeycode);
	void KeyUp(const SDL_Keycode& InKeycode);

private:

};