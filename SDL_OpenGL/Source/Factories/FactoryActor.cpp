
#include "FactoryActor.h"

#include "Actors\PrimitiveActors\ATriangle.h"

std::shared_ptr<AActor> FactoryActor::NewActor(std::string aActorType)
{
	std::shared_ptr<AActor> Actor = nullptr;

	if (aActorType.compare("triangle") == 0)
	{
		Actor = std::make_shared<ATriangle>();
		if (Actor == nullptr)
		{
			Log(DebugType::EDT_Error, "Error creating new actor.");
			return nullptr;
		}
		ATriangle* TriangleActor = static_cast<ATriangle*>(Actor.get());
		TriangleActor->Initiate();

		return Actor;
	}

	return nullptr;
}