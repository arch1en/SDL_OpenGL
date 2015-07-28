#version 400

in vec3 Color;
in vec2 TexCoord;

out vec4 outColor;

uniform sampler2D tex;

layout (location = 0) out vec4 FragColor; 

//uniform BlobSettings 
//{
//	vec4	InnerColor;
//	vec4	OuterColor;
//	float	RadiusInner;
//	float	RadiusOuter;
//};

void main() 
{
	outColor = texture(tex, TexCoord) * vec4(Color, 1.0);
	//float dx = TexCoord.x - 0.5;
	//float dy = TexCoord.y - 0.5;
	//float dist = sqrt(dx * dx + dy * dy);
	//FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}