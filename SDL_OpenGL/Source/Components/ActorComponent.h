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
class AActor;

class ActorComponent : public BaseComponent
{
public:
	ActorComponent(AActor* aOwner )
		: BaseComponent()
		, mRelativePosition{ glm::vec3(0.0f, 0.0f, 0.0f) }
		, mRelativeRotation{ glm::quat(0.0f, 0.0f, 0.0f, 1.0f) }
		, mUpVector{ glm::vec3(0.0f, 1.0f, 0.0f)}
		, mForwardVector{ glm::vec3(0.0f, 0.0f, -1.0f) }
		, mOwner{ aOwner }
	{}


	AActor* GetOwner() const;

protected:
	glm::vec3 mRelativePosition;
	glm::quat mRelativeRotation;

	glm::vec3 mUpVector;
	glm::vec3 mForwardVector;
	glm::vec3 mDirection;

	virtual void Update(float aDeltaTime) override {}

private:
	AActor* mOwner;
};