#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <iostream>
#include <string>

#include <glm.hpp>

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

	bool SendUniformData(const std::string& uniformName, GLint data);
	bool SendUniformData(const std::string& uniformName, GLuint data);
	bool SendUniformData(const std::string& uniformName, GLfloat data);
	
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	bool SendUniformData(const std::string& uniformName, const glm::mat4& data);

	GLuint GetShaderProgramID() const { return mShaderProgramID; }

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

