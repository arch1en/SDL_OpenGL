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
	mInputComponent.Bind("Input.Scene", this, &ACamera::InputListener);
}

void ACamera::InputListener(std::string aCommand)
{
	printf("%s", aCommand.c_str());
}