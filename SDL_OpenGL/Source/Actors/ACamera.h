////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Most basic entity, allows one to see the world and receives input through component.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "AActor.h"
#include "Components/CameraComponent.h"
#include "Components/InputComponent.h"

class ACamera : public AActor
{
public:
	ACamera();

private:
	CameraComponent mCameraComponent;
	InputComponent mInputComponent;

	void InputListener(const KeyData& aKeyData);
};