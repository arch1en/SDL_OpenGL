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
//#include "Components/BaseComponent.h"

class BaseComponent;

class AActor : public Class
{
public:
	AActor();
	~AActor();

	virtual void Update(float aDeltaTime);

	glm::vec3 GetWorldPosition() const;
	glm::quat GetWorldRotation() const;
	glm::vec3 GetUpVector() const;
	glm::vec3 GetDirection() const;
	glm::vec3 GetForwardVector() const;

protected:

	glm::vec3 mWorldPosition;
	glm::quat mWorldRotation;
	// [Temp] TODO : Temporary for lookat function in camera component. will be replaced.
	glm::vec3 mDirection;
	glm::vec3 mUpVector;

	std::vector<BaseComponent*> mComponents;

};