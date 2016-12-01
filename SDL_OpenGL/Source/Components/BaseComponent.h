////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Base class for all components. Components has to derive from this class.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "Core\Class.h"

class BaseComponent : public Class
{
public:
	BaseComponent()
		: Class()
	{

	}
};