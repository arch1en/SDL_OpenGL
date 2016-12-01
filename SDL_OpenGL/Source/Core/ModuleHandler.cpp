////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : This class handles modules behavior. Module is a singleton class that can be accessed around the engine.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "ModuleHandler.h"

void ModuleHandler::InitializeModules()
{
	InputModule::GetSingleton().InitializeLayers();
}