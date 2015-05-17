
#include "stdafx.h"
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
	: m_program(0)
	, m_vertexShader(0)
	, m_fragmentShader(0)
{

}

bool ShaderProgram::Init()
{
	m_program = glCreateProgram();
}

bool ShaderProgram::LoadShader(const char * path, GLenum type)
{
	GLint				shaderSuccess = GL_FALSE;
	std::stringstream	ss;
	std::fstream		shaderFile(path);
	if (shaderFile.is_open())
	{
		ss << shaderFile.rdbuf();
	}

	if (type == GL_VERTEX_SHADER && m_vertexShader <= 0)
	{
		m_vertexShader = glCreateShader(type);
		glShaderSource(m_vertexShader, 1, (const GLchar**)ss.str().c_str(), NULL);
		glCompileShader(m_vertexShader);
		glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &shaderSuccess);
		if (shaderSuccess != GL_TRUE)
		{
			SDL_LogMessage(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_WARN, "Error, cannot compile vertex shader : %d\n", m_vertexShader);
			return false;
		}
	} 
	else if (type == GL_FRAGMENT_SHADER && m_fragmentShader <= 0)
	{
		m_fragmentShader = glCreateShader(type);
		glShaderSource(m_fragmentShader, 1, (const GLchar**)ss.str().c_str(), NULL);
		glCompileShader(m_fragmentShader);
		if (shaderSuccess != GL_TRUE)
		{
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

bool ShaderProgram::LinkProgram()
{
	GLint programSuccess = GL_FALSE;
	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	glLinkProgram(m_program);
	glGetProgramiv(m_program, GL_LINK_STATUS, &programSuccess);
}

bool ShaderProgram::Bind()
{
	glUseProgram(m_program);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Error binding program ! %s\n", gluErrorString(error));
	}
}

bool ShaderProgram::Unbind()
{
	glUseProgram(NULL);
}

GLuint ShaderProgram::getProgramID() const
{
	return m_program;
}