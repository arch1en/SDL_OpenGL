////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Input Module
//  @author     : Artur Ostrowski
//  @usage      : Important part of the project. Input module is responsible for managing activity of input layers.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "IO/InputLayer.h"

#include <unordered_map>

class InputComponent;

class InputModule
{
friend class ModuleHandler;

public:
	InputModule();
	InputModule(const InputModule&) = delete;
	InputModule operator= (const InputModule& RHS) = delete;
	~InputModule();

	static InputModule& GetSingleton()
	{
		static InputModule Module;
		return Module;
	}

	void	RegisterToLayer(InputComponent* aInputComponent, std::string aLayerCategory);
	void	UnregisterFromLayer(InputComponent* aInputComponent, std::string aLayerCategory);

private:

	std::shared_ptr<InputLayer>			EnsuredRegisterToLayer(InputComponent* aInputComponent, std::string aLayerCategory);

	std::unordered_map<std::string, std::shared_ptr<InputLayer>>	mActiveLayers;
	std::unordered_map<std::string, std::shared_ptr<InputLayer>>	mInputLayers;

	bool IsLayerCreated(const std::string& aLayerCategory);

	std::shared_ptr<InputLayer> CreateInputLayer(const std::string& aLayerCategory);
	void DestroyInputLayer(const std::string& aLayerCategory);

	void ActivateLayer();
	void DeactivateLayer();

	void InitializeLayers();
	void Update(SDL_Event& aEvent);

	//	void SetCurrentLayer(std::shared_ptr<InputLayer> InLayer, InputLayerType InLayerType);

};