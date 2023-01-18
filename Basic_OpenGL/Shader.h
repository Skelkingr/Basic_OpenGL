#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <iostream>
#include <string>

#include "glad.h"

class Shader
{
public:
	enum class ShaderType
	{
		VERTEX_SHADER,
		FRAGMENT_SHADER
	};

public:
	static Shader* Instance();

public:
	bool CreateProgram();
	bool CreateShaders();

	bool CompileShaders(const std::string& fileName, ShaderType shaderType);
	void AttachShaders();
	bool LinkProgram();

	void DetachShaders();
	void DestroyShaders();
	void DestroyProgram();

private:
	Shader();
	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

private:
	GLuint mShaderProgramID;
	GLuint mVertexShaderID;
	GLuint mFragmentShaderID;
};

#endif

