////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Allows placing objects that derives from this function onto the scene.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "AActor.h"

#include "Components/BaseComponent.h"

AActor::AActor()
	: Class()
	, mWorldPosition{ glm::vec3(0.0f, 0.0f, 0.0f) }
	, mWorldRotation{ glm::quat(0.0f, 0.0f, 0.0f, 1.0f) }
	, mUpVector{ glm::vec3(0.f, 1.f, 0.f) }
	, mDirection{}
{}

AActor::~AActor()
{

}

void AActor::Update(float aDeltaTime)
{
	for (const auto& Iter : mComponents)
	{
		Iter->Update(aDeltaTime);
	}
}

glm::vec3 AActor::GetWorldPosition() const
{
	return mWorldPosition;
}

glm::quat AActor::GetWorldRotation() const
{
	return mWorldRotation;
}

glm::vec3 AActor::GetUpVector() const
{
	return mUpVector;
}

glm::vec3 AActor::GetDirection() const
{
	return mDirection;
}

glm::vec3 AActor::GetForwardVector() const
{
	return glm::vec3(0.0f, 0.0f, -1.0f);
}