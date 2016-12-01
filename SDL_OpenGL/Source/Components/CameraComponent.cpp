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
	: Position(0.f, 0.f, 0.f)
	, UpVector(0.0f, 1.0f, 0.0f)
	, ForwardVector(0.0f, 0.0f, -1.0f)
	, ViewMatrix(glm::lookAt(Position, Position + ForwardVector, UpVector))
{

}