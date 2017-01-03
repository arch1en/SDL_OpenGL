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
	
	CameraComponent();

protected:
	virtual void Update(float aDeltaTime) override;
private:
	
	glm::mat4 ViewMatrix;

};

