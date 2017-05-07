////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Component that allows actor to see the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "ActorComponent.h"

class CameraComponent : public ActorComponent
{
public:
	
	CameraComponent(AActor* aOwner);
	// @return - Error code.
	// 0 - Success.
	// 1 - Actor Attached is invalid.
	int			GetViewMatrix(glm::mat4& aMatrix) const;
protected:
	virtual void Update(float aDeltaTime) override;
private:
	
	glm::mat4 mViewMatrix;

};

