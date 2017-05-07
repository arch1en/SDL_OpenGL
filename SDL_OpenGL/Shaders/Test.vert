#version 430 core

layout(location = 0) in vec4 vPosition;
layout(location = 2) in vec2 vTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vPosition;
	vTexCoord = vec2(TexCoord.x, 1.0 - TexCoord.y);
}