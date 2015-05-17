
#pragma once

class ShaderProgram
{

public:

	ShaderProgram();

	bool	Init();
	bool	LoadShader(const char * path, GLenum type);
	bool	LinkProgram();
	bool	Bind();
	bool	Unbind();
	GLuint	getProgramID() const;

private:

	GLuint		m_program;
	GLuint		m_vertexShader;
	GLuint		m_fragmentShader;

};