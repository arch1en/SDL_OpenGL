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
#include "Components/ActorComponent.h"

AActor::AActor()
	: Class()
	, mRootComponent{nullptr}
{
	mRootComponent = new ActorComponent(this);
}

AActor::~AActor()
{
	delete mRootComponent;
}

void AActor::Update(float aDeltaTime)
{
	for (const auto& Iter : mComponents)
	{
		Iter->Update(aDeltaTime);
	}
}

void AActor::SetWorldPosition(const glm::vec3 aPosition)
{
	mRootComponent ? mRootComponent->SetWorldPosition(aPosition) : Log(DebugType::EDT_Fatal, "Cannot perform SetWorldPosition, RootComponent invalid !");
}

void AActor::SetWorldRotation(const glm::quat aRotation)
{
	mRootComponent ? mRootComponent->SetWorldRotation(aRotation) : Log(DebugType::EDT_Fatal, "Cannot perform SetWorldRotation, RootComponent invalid !");
}

void AActor::SetFacingDirection(const glm::vec3 aDirection)
{
	mRootComponent ? mRootComponent->SetFacingDirection(aDirection) : Log(DebugType::EDT_Fatal, "Cannot perform SetFacingDirection, RootComponent invalid !");
}

const glm::vec3 AActor::GetWorldPosition() const
{
	if (mRootComponent == nullptr)
	{
		Log(DebugType::EDT_Fatal, "Cannot perform GetWorldPosition, RootComponent invalid !");
		return glm::vec3();
	}

	return mRootComponent->GetWorldPosition();
}

const glm::quat AActor::GetWorldRotation() const
{
	if (mRootComponent == nullptr)
	{
		Log(DebugType::EDT_Fatal, "Cannot perform GetWorldRotation, RootComponent invalid !");
		return glm::quat();
	}

	return mRootComponent->GetWorldRotation();
}

const glm::vec3 AActor::GetUpVector() const
{
	if (mRootComponent == nullptr)
	{
		Log(DebugType::EDT_Fatal, "Cannot perform GetUpVector, RootComponent invalid !");
		return glm::vec3();
	}

	return mRootComponent->GetUpVector();
}

const glm::vec3 AActor::GetForwardVector() const
{
	if (mRootComponent == nullptr)
	{
		Log(DebugType::EDT_Fatal, "Cannot perform GetForwardVector, RootComponent invalid !");
		return glm::vec3();
	}

	return mRootComponent->GetForwardVector();;
}