////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : A 2D triangle actor able to be placed on the screen.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "Source/Actors/AActor.h"
#include "Components\MeshComponent.h"

class ATriangle : public AActor
{
public:
	ATriangle();
	void Initiate();

private:

	std::shared_ptr<MeshComponent> mMeshComponent;
};