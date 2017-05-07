////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Component that allows actor to see the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "CameraComponent.h"

CameraComponent::CameraComponent(AActor* aOwner)
	: ActorComponent{aOwner}
	, mViewMatrix()
{
	mComponentType = "Camera";
}

void CameraComponent::Update(float aDeltaTime)
{

}

int	CameraComponent::GetViewMatrix(glm::mat4& aMatrix) const
{
	if (GetOwner() == nullptr) return 1;

	aMatrix = glm::lookAt(GetOwner()->GetWorldPosition(), GetOwner()->GetWorldPosition() + GetOwner()->GetForwardVector(), GetOwner()->GetUpVector());

	return 0;
}