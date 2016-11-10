#include "InputManager.h"
#include "IO/ConfigLoader.h"

InputManager::InputManager()
{
	Name = "InputManager";
	InitializeLayers();
}

InputManager::~InputManager()
{

}

void InputManager::InitializeLayers()
{
	std::map<std::string, std::string> SceneInput;
	ConfigLoader::GetInstance().LoadConfigData("InputProperties", "Scene.Input", SceneInput);

	std::shared_ptr<KeyboardInputLayer> SceneInputLayer( new KeyboardInputLayer("Scene", "Scene.Input", SceneInput));

	mKeyboardInputLayers.push_back(SceneInputLayer);

	mCurrentKeyboardLayer = SceneInputLayer;

}

void InputManager::Update(SDL_Event& InEvent)
{
	Broadcast();

	if (InEvent.type == SDL_KEYDOWN)
	{
		mCurrentKeyboardLayer->KeyDown(InEvent.key.keysym.sym);
	}
	if (InEvent.type == SDL_KEYUP)
	{
		mCurrentKeyboardLayer->KeyUp(InEvent.key.keysym.sym);
	}
}