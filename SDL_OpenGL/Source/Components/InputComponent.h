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
		for (const std::string& Layer : mLayersBoundTo)
		{
			InputModule::GetSingleton().UnregisterFromLayer(this, Layer);
		}
	}
	  

	template <typename ClassType>
	void BindIntermittent(const std::string& aLayerName, ClassType* aReference, void(ClassType::*aTMethod)(const KeyData&))
	{
		std::function<void(const KeyData&)> Delegate = std::bind(aTMethod, aReference, std::placeholders::_1);
		RegisterToLayer(aLayerName);
		mIntermittentDelegates.push_back(Delegate);
	}

	template <typename ClassType>
	void BindContinuous(const std::string& aLayerName, ClassType* aReference, void(ClassType::*aTMethod)(const KeyData&))
	{
		std::function<void(const KeyData&)> Delegate = std::bind(aTMethod, aReference, std::placeholders::_1);
		RegisterToLayer(aLayerName);
		mContinuousDelegates.push_back(Delegate);
	}

	inline std::vector<std::function<void(const KeyData&)>>& GetIntermittentDelegates() { return mIntermittentDelegates; }
	inline std::vector<std::function<void(const KeyData&)>>& GetContinuousDelegates() { return mContinuousDelegates; }
protected:

	void Update(float aDeltaTime) override {}

private:
	std::vector<std::function<void(const KeyData&)>>	mContinuousDelegates;
	std::vector<std::function<void(const KeyData&)>>	mIntermittentDelegates;
	std::vector<std::string>						mLayersBoundTo;

	void RegisterToLayer(const std::string& aLayerName)
	{
		bool RegisterResult = InputModule::GetSingleton().RegisterToLayer(this, aLayerName);


		if (RegisterResult == true)
		{
			auto& Result = std::find(mLayersBoundTo.begin(), mLayersBoundTo.end(), aLayerName);

			if (Result == mLayersBoundTo.end())
			{
				mLayersBoundTo.push_back(aLayerName);
			}
		}
	}
};