#version 330 core

in vec3 aVertColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D aTexture;

void main() 
{
	FragColor = texture(aTexture, TexCoord);
}