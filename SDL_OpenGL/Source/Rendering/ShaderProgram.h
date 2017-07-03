////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Shader Program
//  @author     : Artur Ostrowski
//  @usage      : Keeps shader program data and handles it.
//  @version    : 1.0.0
//
////////////////////////////////////////
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

	bool		CheckProgramStatus();
	bool		CheckShaderStatus(GLuint shaderID);

	int			GetUniformLocation(const char* aName) const;

private:

	GLuint		m_program;
	GLuint		m_vertexShader;
	GLuint		m_fragmentShader;
};