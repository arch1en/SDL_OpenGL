#include "Camera.h"

Camera::Camera()
	: Position(0.f, 0.f, 0.f)
	, UpVector(0.0f, 1.0f, 0.0f)
	, ForwardVector(0.0f, 0.0f, -1.0f)
	, ViewMatrix(glm::lookAt(Position, Position + ForwardVector, UpVector))
	, mInputComponent()
{

	mInputComponent.OnEventDelegate = []() {

		Log(DebugType::EDT_Notice, "WERKS");
	
	};
}