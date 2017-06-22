#include "ACube.h"
#include "FactoryMesh.h"

ACube::ACube()
{

}

void ACube::Initiate()
{
	mMeshComponent = std::make_shared<MeshComponent>(this);

	FactoryMesh* Factory = FactoryMesh::GetInstance();
	Factory->NewMesh(mMeshComponent, "cube");
}