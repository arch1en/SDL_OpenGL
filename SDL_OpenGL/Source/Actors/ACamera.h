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
#include "Components/MovementComponent.h"
#include "Components/InputComponent.h"

class ACamera : public AActor
{
public:
	ACamera();
	~ACamera();

	const std::shared_ptr<CameraComponent> GetCameraComponent() const;

private:
	virtual void Update(float aDeltaTime) override;

	std::shared_ptr<CameraComponent>	mCameraComponent;
	std::shared_ptr<InputComponent>		mInputComponent;
	std::shared_ptr<MovementComponent>	mMovementComponent;

	void InputListener(const KeyData& aKeyData);
	void MouseMotionListener(const MouseData& aMouseData);
};