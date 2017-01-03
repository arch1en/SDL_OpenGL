////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Component that allows actor to see the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "CameraComponent.h"

CameraComponent::CameraComponent()
	: ViewMatrix(glm::lookAt(mPosition, mPosition + mForwardVector, mUpVector))
{

}

void CameraComponent::Update(float aDeltaTime)
{

}