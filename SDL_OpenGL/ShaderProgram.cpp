
#include "stdafx.h"
#include "ShaderProgram.h"


ShaderProgram::ShaderProgram()
	: m_program(0)
	, m_vertexShader(0)
	, m_fragmentShader(0)
{

}

void ShaderProgram::Init()
{
	m_program = glCreateProgram();
}

bool ShaderProgram::LoadShader(const char * path, GLenum type)
{
	GLint				shaderSuccess = GL_FALSE;
	std::fstream		shaderFile(path);

	std::string			buffer(	(std::istreambuf_iterator<char>(shaderFile)),
								std::istreambuf_iterator<char>() );

	const char * source = buffer.c_str();

	if (type == GL_VERTEX_SHADER && m_vertexShader <= 0)
	{
		// Create shader
		m_vertexShader = glCreateShader(type);
		// Pass it's source to created shader
		glShaderSource(m_vertexShader, 1, &source, NULL);
		// Compile it
		glCompileShader(m_vertexShader);
		// Check for errors
		glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &shaderSuccess);
		if (shaderSuccess != GL_TRUE)
		{
			char buffer[512];
			glGetShaderInfoLog(m_vertexShader, 512, NULL, buffer);
			printf("Vertex shader Log: \n\n%s\n", buffer);
			SDL_LogMessage(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_WARN, "Error, cannot compile vertex shader : %d\n", m_vertexShader);
			return false;
		}
	} 
	else if (type == GL_FRAGMENT_SHADER && m_fragmentShader <= 0)
	{
		m_fragmentShader = glCreateShader(type);
		glShaderSource(m_fragmentShader, 1, &source, NULL);
		glCompileShader(m_fragmentShader);
		glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &shaderSuccess);
		if (shaderSuccess != GL_TRUE)
		{
			char buffer[512];
			glGetShaderInfoLog(m_fragmentShader, 512, NULL, buffer);
			printf("Fragment shader Log: \n\n%s\n", buffer);
			SDL_LogMessage(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_WARN, "Error, cannot compile fragment shader : %d\n", m_fragmentShader);
			return false;
		}
	}
	else
	{
		// TODO implement glshaderinfolog
		SDL_LogMessage(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_WARN, "Error, cannot load %d shader./n"
						, type == GL_VERTEX_SHADER ? "vertex" : type == GL_FRAGMENT_SHADER ? "fragment" : "undefined");
		return false;
	}

	return true;
}

void ShaderProgram::LinkProgram()
{
	GLint programSuccess = GL_FALSE;
	if (m_program <= 0 || m_vertexShader <= 0 || m_fragmentShader <= 0)
	{
		printf("Error, cannot link program : \n\nm_program : %u\nm_vertexShader : %u\nm_fragmentShader : %u", m_program, m_vertexShader, m_fragmentShader);
	}
	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	glLinkProgram(m_program);
	glGetProgramiv(m_program, GL_LINK_STATUS, &programSuccess);
}

void ShaderProgram::Bind()
{
	glUseProgram(m_program);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Error binding program ! %s\n");
		//SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Error binding program ! %s\n", gluErrorString(error));
	}

}

void ShaderProgram::Unbind()
{
	glUseProgram(NULL);
}

GLuint ShaderProgram::getProgramID() const
{
	return m_program;
}