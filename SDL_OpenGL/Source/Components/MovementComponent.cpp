
#include "MovementComponent.h"

MovementComponent::MovementComponent()
	: mSpeed{0.f}
	, mDirection{glm::vec3(0.f, 0.f, 0.f)}
{

}

void MovementComponent::SetSpeed(float aSpeed)
{
	mSpeed = aSpeed;
}

void MovementComponent::SetDirection(glm::vec3 aDirection)
{
	mDirection = aDirection;
}

void MovementComponent::Update(float aDeltaTime)
{

}

const float MovementComponent::GetSpeed() const
{
	return mSpeed;
}
const glm::vec3 MovementComponent::GetDirection() const
{
	return mDirection;
}

const glm::vec3 MovementComponent::GetCalculatedMovement()
{
	return mSpeed * mDirection;
}