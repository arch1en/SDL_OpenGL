#include "KeyboardInputLayer.h"

KeyboardInputLayer::KeyboardInputLayer(std::string InName, std::string InLayoutName)
	: InputLayer(InName, InLayoutName)
{

}

KeyboardInputLayer::KeyboardInputLayer(std::string InName, std::string InLayerName, std::map<std::string, std::string> InKeyMap)
	: InputLayer(InName, InLayerName, InKeyMap)
{

}

void KeyboardInputLayer::KeyDown(const SDL_Keycode& InKeycode)
{

}


void KeyboardInputLayer::KeyUp(const SDL_Keycode& InKeycode)
{

}
