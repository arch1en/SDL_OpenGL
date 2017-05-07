////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Base class for all components. Components has to derive from this class.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "BaseComponent.h"

const std::string BaseComponent::GetComponentType() const
{
	return mComponentType;
}