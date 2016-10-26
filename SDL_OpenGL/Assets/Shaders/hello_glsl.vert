#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

out vec3 vertColor;

void main() 
{
	//Texcoord = texcoord;

	vertColor = Color;

	gl_Position = /*trans **/ vec4(Position, 1.0);
}