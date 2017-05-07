#include "ATriangle.h"
#include "FactoryMesh.h"

ATriangle::ATriangle()
{

}

void ATriangle::Initiate()
{
	mMeshComponent = std::make_shared<MeshComponent>(this);

	FactoryMesh* Factory = FactoryMesh::GetInstance();
	Factory->NewMesh(mMeshComponent, "triangle");
}