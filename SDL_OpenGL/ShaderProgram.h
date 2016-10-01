
#pragma once

class ShaderProgram
{

public:

	ShaderProgram();

	void	Init();
	bool	LoadShader(const char * path, GLenum type);
	void	LinkProgram();
	void	Bind();
	void	Unbind();
	void	PrintInfo();
	GLuint	getProgramID() const;

private:

	GLuint		m_program;
	GLuint		m_vertexShader;
	GLuint		m_fragmentShader;
	bool		CheckShaderStatus(GLuint shaderID);
	bool		CheckProgramStatus(GLuint programID);
};