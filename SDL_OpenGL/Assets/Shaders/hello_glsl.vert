#version 400

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;

out vec3 Color;

uniform mat4 RotationMatrix;

void main() 
{ 
	Color = vertexColor;
	gl_Position = RotationMatrix * vec4(vertexPosition, 1.0);
}