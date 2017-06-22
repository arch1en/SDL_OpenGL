////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : A 3D cube actor able to be placed on the screen.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "Source/Actors/AActor.h"
#include "Components\MeshComponent.h"

class ACube : public AActor
{
public:
	ACube();
	void Initiate();

private:

	std::shared_ptr<MeshComponent> mMeshComponent;
};