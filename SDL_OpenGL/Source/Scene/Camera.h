#pragma once

#include "stdafx.h"

#include "Components\InputComponent.h"

class Camera 
{
public:
	
	Camera();
	//void Update(float DeltaTime);

	
	InputComponent		mInputComponent;

private:
	glm::vec3 Position;
	glm::vec3 UpVector;
	glm::vec3 ForwardVector;
	
	glm::mat4 ViewMatrix;

};

