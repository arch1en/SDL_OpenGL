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

#include "Components\InputComponent.h"

class CameraComponent 
{
public:
	
	CameraComponent();
	//void Update(float DeltaTime);
	
private:
	glm::vec3 Position;
	glm::vec3 UpVector;
	glm::vec3 ForwardVector;
	
	glm::mat4 ViewMatrix;

};

