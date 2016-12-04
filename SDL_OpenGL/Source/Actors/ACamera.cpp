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
	mInputComponent.BindContinuous("Input.Scene", this, &ACamera::InputListener);
}

void ACamera::InputListener(const KeyData& aKeyData)
{
	printf("%s", aKeyData.Command.c_str());
}