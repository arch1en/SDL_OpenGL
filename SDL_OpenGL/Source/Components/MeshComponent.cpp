
#include "MeshComponent.h"
#include "Factories\FactoryMesh.h"

void MeshComponent::SetMesh(std::shared_ptr<MeshBase> aMesh)
{
	mMesh = aMesh;
}

void MeshComponent::Update(float aDeltaTime)
{
	ActorComponent::Update(aDeltaTime);
}

std::shared_ptr<MeshBase> MeshComponent::GetMesh() const
{
	return mMesh;
}