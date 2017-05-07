#pragma once

#include "stdafx.h"
#include "ActorComponent.h"

class MeshBase;

class MeshComponent : public ActorComponent
{
public:
	MeshComponent(AActor* aOwner)
		:ActorComponent{ aOwner }
	{}
	void SetMesh(std::shared_ptr<MeshBase> aMesh);
	std::shared_ptr<MeshBase> GetMesh() const;
	virtual void Update(float aDeltaTime) override;

private:

	std::shared_ptr<MeshBase>	mMesh;

};