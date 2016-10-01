#version 150 core

in vec3 position;
in vec3 color;
//in vec2 texcoord;

out vec3 Color;
//out vec2 Texcoord;

//uniform mat4 trans;

void main() {
	Color = color;
	//Texcoord = texcoord;

	gl_Position = /*trans **/ vec4(position, 1.0);
}