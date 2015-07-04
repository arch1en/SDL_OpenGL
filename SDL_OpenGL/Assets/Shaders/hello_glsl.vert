#version 400

in vec2 vertexPosition;
in vec3 vertexColor;

out vec3 Color;

void main() 
{ 
	Color = vertexColor;
	gl_Position = vec4(vertexPosition, 0.0, 1.0);
}