#pragma once

#include "stdafx.h"

#include "IO/KeyboardInputLayer.h"
#include "IO/MouseInputLayer.h"

enum InputLayerType
{
	ILT_None,
	ILT_Keyboard,
	ILT_Mouse,
	ILT_Total
};

class InputManager : public ISubject
{
public:
	InputManager();
	InputManager(const InputManager&) = delete;
	InputManager operator= (const InputManager& RHS) = delete;
	~InputManager();

	std::shared_ptr<KeyboardInputLayer>	mCurrentKeyboardLayer;
	std::shared_ptr<MouseInputLayer>	mCurrentMouseLayer;

	std::vector<std::shared_ptr<KeyboardInputLayer>>	mKeyboardInputLayers;
	std::vector<std::shared_ptr<MouseInputLayer>>		mMouseInputLayers;

	void InitializeLayers();
	void Update(SDL_Event& InEvent);

	//	void SetCurrentLayer(std::shared_ptr<InputLayer> InLayer, InputLayerType InLayerType);

};