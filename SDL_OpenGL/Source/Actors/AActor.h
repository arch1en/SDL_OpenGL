////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Allows placing objects that derives from this function onto the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "Core/Class.h"
#include <glm/gtc/quaternion.hpp>

class AActor : public Class
{
public:
	AActor()
		: Class()
		, mPosition{glm::vec3(0.0f, 0.0f, 0.0f)}
		, mRotation{glm::quat(0.0f, 0.0f, 0.0f, 1.0f)}
	{}
protected:

	glm::vec3 mPosition;
	glm::quat mRotation;
};