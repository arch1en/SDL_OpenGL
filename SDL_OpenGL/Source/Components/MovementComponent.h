////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Component that determines actor movement.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "BaseComponent.h"

class MovementComponent : public BaseComponent
{
public:

	MovementComponent();

	void SetSpeed(float aSpeed);
	void SetDirection(glm::vec3 aDirection);
	const float GetSpeed() const;
	const glm::vec3 GetDirection() const;

	const glm::vec3 GetCalculatedMovement();

protected:

	float		mSpeed;
	glm::vec3	mDirection;

	virtual void Update(float aDeltaTime) override;
};