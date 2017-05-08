////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Input Module
//  @author     : Artur Ostrowski
//  @usage      : Important part of the project. Input module is responsible for managing activity of input layers.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "InputModule.h"
#include "IO/ConfigLoader.h"

InputModule::InputModule()
{
	InitializeLayers();
}

InputModule::~InputModule()
{

}

void InputModule::InitializeLayers()
{
	std::string LayerCategory = "Input.Scene";

	std::shared_ptr<InputLayer> Layer = CreateInputLayer(LayerCategory);

	mInputLayers.insert({ LayerCategory, Layer });
	mActiveLayers.insert({ LayerCategory, Layer });
}

void InputModule::Update(SDL_Event& aEvent)
{

	if (aEvent.type == SDL_KEYDOWN || 
		aEvent.type == SDL_KEYUP ||
		aEvent.type == SDL_MOUSEBUTTONDOWN ||
		aEvent.type == SDL_MOUSEBUTTONUP)
	{
		for (auto& Iter : mActiveLayers)
		{
			Iter.second->PrepareAndBroadcastIntermittentCommand(aEvent.key.keysym.sym);
		}
	}

	if (aEvent.type == SDL_MOUSEMOTION)
	{
		for (auto& Iter : mActiveLayers)
		{
			Iter.second->BroadcastMouseMotionCommand(mLastMouseX, mLastMouseY);
		}
	}
}

void InputModule::Update()
{
	const Uint8*	KeyArray = SDL_GetKeyboardState(NULL);

	for (auto& Iter : mActiveLayers)
	{
		for (auto& KeyPair : Iter.second->GetKeyMap())
		{
			if (KeyArray[static_cast<Uint8>(SDL_GetScancodeFromKey(static_cast<SDL_Keycode>(KeyPair.first)))] == 1)
			{
				KeyData Data;

				Data.Key = KeyPair.first;
				Data.Command = KeyPair.second;

				Iter.second->BroadcastContinuousCommand(Data);
			}
		}
	}
}

bool	InputModule::RegisterToLayer(InputComponent* aInputComponent, std::string aLayerCategory)
{
	auto Result = mInputLayers.find(aLayerCategory);

	if (Result != mInputLayers.end())
	{
		Result->second->BindComponent(aInputComponent);
		return true;
	}
	else
	{
		Log(DebugType::EDT_Error, "Cannot register component to layer. Component already registered.");
		return false;
	}

	return false;
}

// TODO : Decide what to do with this.
std::shared_ptr<InputLayer>	InputModule::EnsuredRegisterToLayer(InputComponent* aInputComponent, std::string aLayerCategory)
{
	try
	{
		auto Result = mInputLayers.at(aLayerCategory);
	}
	catch (std::out_of_range Exception)
	{
		std::shared_ptr<InputLayer> NewLayer = CreateInputLayer(aLayerCategory);
		NewLayer->BindComponent(aInputComponent);
		mInputLayers.insert({ aLayerCategory, NewLayer });

		return NewLayer;
	}

	return nullptr;
}

void InputModule::UnregisterFromLayer(InputComponent* aInputComponent, std::string aLayerCategory)
{
	auto Result = mInputLayers.find(aLayerCategory);

	if (Result == mInputLayers.end())
	{
		Log(DebugType::EDT_Error, "Cannot unregister from layer, missing layer in array.");
		return;
	}

	mInputLayers.at(aLayerCategory)->UnbindComponent(aInputComponent);
}

std::shared_ptr<InputLayer> InputModule::CreateInputLayer(const std::string& aLayerCategory)
{

	if (IsLayerCreated(aLayerCategory) == false)
	{
		std::map<char, std::string> LayerInput;

		const int ErrorCheck = ConfigLoader::GetInstance().LoadInputData("InputProperties", aLayerCategory, LayerInput);

		if (ErrorCheck > 0)
		{
			Log(DebugType::EDT_Error, "Cannot create input layer. Error reading config file.");
			return nullptr;
		}

		std::shared_ptr<InputLayer> InputLayer(std::make_shared<InputLayer>(InputLayer(aLayerCategory, LayerInput)));

		return InputLayer;
	}

	return nullptr;
}

void InputModule::DestroyInputLayer(const std::string& aLayerCategory)
{
	const int ErasedLayers = mInputLayers.erase(aLayerCategory);
}

bool InputModule::IsLayerCreated(const std::string& aLayerCategory)
{
	auto Result = mInputLayers.find(aLayerCategory);

	if (Result != mInputLayers.end())
	{
			return true;
	}
	
	return false;
}