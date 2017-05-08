////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Most basic entity, allows one to see the world and receives input through component.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "ACamera.h"

ACamera::ACamera()
	: AActor()
{
	mCameraComponent = std::make_shared<CameraComponent>(this);
	if (mCameraComponent != nullptr)
	{
		BaseComponent* Component = static_cast<BaseComponent*>(mCameraComponent.get());
		mComponents.push_back(Component);
	}
	mInputComponent = std::make_shared<InputComponent>();
	if (mInputComponent != nullptr)
	{
		BaseComponent* Component = static_cast<BaseComponent*>(mInputComponent.get());
		mComponents.push_back(Component);
	}
	mMovementComponent = std::make_shared<MovementComponent>();
	if (mMovementComponent != nullptr)
	{
		BaseComponent* Component = static_cast<BaseComponent*>(mMovementComponent.get());
		mComponents.push_back(Component);
	}

	mInputComponent->BindContinuous("Input.Scene", this, &ACamera::InputListener);
	mInputComponent->BindMouseMotion("Input.Scene", this, &ACamera::MouseMotionListener);
	mMovementComponent->SetSpeed(1.f);
}

ACamera::~ACamera()
{
	mCameraComponent.reset();
	mInputComponent.reset();
	mMovementComponent.reset();
}

void ACamera::InputListener(const KeyData& aKeyData)
{
	if (aKeyData.Command.compare("MoveForward") == 0)
	{
		mMovementComponent->SetDirection(glm::vec3(0.f, 0.f, -1.f));
	}
	else if (aKeyData.Command.compare("MoveBackwards") == 0)
	{
		mMovementComponent->SetDirection(glm::vec3(0.f, 0.f, 1.f));
	}
	else if (aKeyData.Command.compare("StrafeLeft") == 0)
	{
		mMovementComponent->SetDirection(glm::vec3(-1.f, 0.f, 0.f));
	}
	else if (aKeyData.Command.compare("StrafeRight") == 0)
	{
		mMovementComponent->SetDirection(glm::vec3(1.f, 0.f, 0.f));
	}

	mWorldPosition += mMovementComponent->GetCalculatedMovement();
}

void ACamera::MouseMotionListener(const MouseData& aMouseData)
{

}

void ACamera::Update(float aDeltaTime)
{
	AActor::Update(aDeltaTime);


}

const std::shared_ptr<CameraComponent> ACamera::GetCameraComponent() const
{
	return mCameraComponent;
}