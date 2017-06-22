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
#include "InputComponent.h"

InputComponent::~InputComponent()
{
	for (const std::string& Layer : mLayersBoundTo)
	{
		InputModule::GetSingleton().UnregisterFromLayer(this, Layer);
	}
}

void InputComponent::RegisterToLayer(const std::string& aLayerName)
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

void InputComponent::SetGrabInput(bool aState)
{
	SDL_SetRelativeMouseMode(aState ? SDL_TRUE : SDL_FALSE);
}