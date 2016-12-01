////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : This class handles modules behavior. Module is a singleton class that can be accessed around the engine.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "Modules/InputModule.h"

class ModuleHandler
{
public:

	void InitializeModules();

	template<typename Class, typename... Args>
	void UpdateModule(Args... args)
	{
		Class::GetSingleton().Update(args...);
	}
};