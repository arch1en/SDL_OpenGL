////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Actor Component
//  @author     : Artur Ostrowski
//  @usage      : Component allowed and designated only for actors.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"
#include "BaseComponent.h"

#include <glm/gtc/quaternion.hpp>

class ActorComponent : BaseComponent
{
public:
	ActorComponent()
		: BaseComponent()
		, mPosition{ glm::vec3(0.0f, 0.0f, 0.0f) }
		, mRotation{ glm::quat(0.0f, 0.0f, 0.0f, 1.0f) }
		, mUpVector{ glm::vec3(0.0f, 1.0f, 0.0f)}
		, mForwardVector{ glm::vec3(0.0f, 0.0f, -1.0f) }
	{}

protected:
	glm::vec3 mPosition;
	glm::quat mRotation;

	glm::vec3 mUpVector;
	glm::vec3 mForwardVector;

	virtual void Update(float aDeltaTime) override {}
};