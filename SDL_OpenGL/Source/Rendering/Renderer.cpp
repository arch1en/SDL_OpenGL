////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Renderer
//  @author     : Artur Ostrowski
//  @usage      : Base class responsible for rendering tasks.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "Renderer.h"
Renderer::Renderer()
{
	DrawingMode = GL_TRIANGLES;
	ParametersInOneVector = 3 * 12;
}

Renderer::~Renderer()
{

}

void Renderer::AddMeshToDraw(std::shared_ptr<MeshComponent> InMesh)
{
	Meshes.push_back(InMesh);
}

void Renderer::DrawMeshes(const GLsizei aVAOIndex,
	const glm::mat4& aViewMatrix,
	const GLint aModelUniformLocation,
	const GLint aViewUniformLocation,
	const GLint aProjectionUniformLocation)
{
	glBindVertexArray(aVAOIndex);

	for (auto& iter : Meshes)
	{
		assert(iter != nullptr);
		//glDrawArrays(DrawingMode, 0, 3);
		glm::mat4 ModelMatrix;
		ModelMatrix = glm::translate(ModelMatrix, iter->GetOwner()->GetWorldPosition());
		glUniformMatrix4fv(aModelUniformLocation, 1, GL_FALSE, &ModelMatrix[0][0]);

		glUniformMatrix4fv(aViewUniformLocation, 1, GL_FALSE, &aViewMatrix[0][0]);

		glm::mat4 ProjectionMatrix;
		ProjectionMatrix = glm::perspective(90.0f, (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
		glUniformMatrix4fv(aProjectionUniformLocation, 1, GL_FALSE, &ProjectionMatrix[0][0]);

		glDrawElements(DrawingMode, ParametersInOneVector, GL_UNSIGNED_INT, 0);// &iter->mPolygonData.Elements[0]);
		// TODO [High] : Handle VAO Binding !

	}
	glBindVertexArray(0);

}