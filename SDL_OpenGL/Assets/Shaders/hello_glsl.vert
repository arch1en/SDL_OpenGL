#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

out vec3 vertColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	//Texcoord = texcoord;

	vertColor = Color;

	gl_Position = /*trans **/ projection * view * model * vec4(Position, 1.0);
}