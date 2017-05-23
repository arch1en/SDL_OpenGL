#include "ActorComponent.h"

AActor* ActorComponent::GetOwner() const
{
	return mOwner;
}

void ActorComponent::SetWorldPosition(const glm::vec3 aPosition)
{
	mWorldPosition = aPosition;
}

void ActorComponent::SetWorldRotation(const glm::quat aRotation)
{
	mWorldRotation = aRotation;
}

void ActorComponent::SetFacingDirection(const glm::vec3 aDirection)
{
	mForwardVector = glm::normalize(aDirection);
}

void ActorComponent::SetRelativePosition(const glm::vec3 aPosition)
{
	mWorldPosition = mWorldPosition + aPosition;
	mRelativePosition = aPosition;
}

void ActorComponent::SetRelativeRotation(const glm::quat aRotation)
{
	mWorldRotation = mWorldRotation + aRotation;
	mRelativeRotation = aRotation;
}

const glm::vec3 ActorComponent::GetWorldPosition() const
{
	return mWorldPosition;
}
const glm::quat ActorComponent::GetWorldRotation() const
{
	return mWorldRotation;
}

const glm::vec3 ActorComponent::GetRelativePosition() const
{
	return mRelativePosition;
}
const glm::quat ActorComponent::GetRelativeRotation() const
{
	return mRelativeRotation;
}

const glm::vec3 ActorComponent::GetUpVector() const
{
	return mUpVector;
}

const glm::vec3 ActorComponent::GetForwardVector() const
{
	return mForwardVector;
}

