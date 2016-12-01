////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Component that allows :
//					- Registering to input layers.
//					- Sends input with help of InputLayers and InputModule to interested delegates.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include <memory>
#include <functional>

#include "BaseComponent.h"
#include "Modules\InputModule.h"

class Class;

class InputComponent : public BaseComponent
{
public:
	InputComponent() 
		: BaseComponent()
	{  }

	~InputComponent()
	{
		for (std::shared_ptr<InputLayer>& Layer : mLayersBoundTo)
		{
			InputModule::GetSingleton().UnregisterFromLayer(this, Layer->GetCategory());
		}
	}
	  

	template <typename ClassType>
	void Bind(const std::string& aLayerName, ClassType* aReference, void(ClassType::*aTMethod)(std::string))
	{
		std::function<void(std::string)> Delegate = std::bind(aTMethod, aReference, std::placeholders::_1);
		InputModule::GetSingleton().RegisterToLayer(this, aLayerName);
		mDelegates.push_back(Delegate);
	}

	std::vector<std::function<void(std::string)>>& GetDelegates() { return mDelegates; }

private:
	std::vector<std::function<void(std::string)>>	mDelegates;
	std::vector<std::shared_ptr<InputLayer>>		mLayersBoundTo;

};