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
	friend class InputLayer;

public:
	InputComponent() 
		: BaseComponent()
	{  }

	~InputComponent();

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

	template <typename ClassType>
	void BindMouseMotion(const std::string& aLayerName, ClassType* aReference, void(ClassType::*aTMethod)(const MouseData&))
	{
		std::function<void(const MouseData&)> Delegate = std::bind(aTMethod, aReference, std::placeholders::_1);
		RegisterToLayer(aLayerName);
		mMouseMotionDelegates.push_back(Delegate);
	}

	inline std::vector<std::function<void(const KeyData&)>>& GetIntermittentDelegates() { return mIntermittentDelegates; }
	inline std::vector<std::function<void(const KeyData&)>>& GetContinuousDelegates() { return mContinuousDelegates; }
	inline std::vector<std::function<void(const MouseData&)>>& GetMouseMotionDelegates() { return mMouseMotionDelegates; }
	inline const glm::vec2&	GetLastMousePosition() const { return mLastMousePosition; }
	inline const float	GetMouseSensitivity() const { return mMouseSensitivity; }

	void SetGrabInput(bool aState);

protected:

	void Update(float aDeltaTime) override {}

private:

	float			mMouseSensitivity = 0.01f;
	glm::vec2		mLastMousePosition = glm::vec2{ 0, 0 };

	std::vector<std::function<void(const KeyData&)>>	mContinuousDelegates;
	std::vector<std::function<void(const KeyData&)>>	mIntermittentDelegates;
	std::vector<std::function<void(const MouseData&)>>	mMouseMotionDelegates;
	std::vector<std::string>							mLayersBoundTo;

	void RegisterToLayer(const std::string& aLayerName);

};