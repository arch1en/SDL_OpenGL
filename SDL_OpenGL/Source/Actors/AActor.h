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

class BaseComponent;
class ActorComponent;

class AActor : public Class
{
public:
	AActor();
	~AActor();

	virtual void Update(float aDeltaTime);

	void SetWorldPosition(const glm::vec3 aPosition);
	void SetWorldRotation(const glm::quat aRotation);
	void SetFacingDirection(const glm::vec3 aDirection);

	const glm::vec3 GetWorldPosition() const;
	const glm::quat GetWorldRotation() const;
	const glm::vec3 GetUpVector() const;
	const glm::vec3 GetForwardVector() const;
	const glm::vec3 GetRightVector() const;

protected:

	ActorComponent*				mRootComponent;

	std::vector<BaseComponent*> mComponents;

};