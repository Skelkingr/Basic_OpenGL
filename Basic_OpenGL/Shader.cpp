#include "Shader.h"

Shader* Shader::Instance()
{
	static Shader* shaderObject = new Shader();
	return shaderObject;
}

Shader::Shader()
	:
	mShaderProgramID(0),
	mVertexShaderID(0),
	mFragmentShaderID(0)
{}

bool Shader::CreateProgram()
{
	mShaderProgramID = glCreateProgram();

	if (mShaderProgramID == 0)
	{
		std::cout << "[ERR] Error creating shader program." << std::endl;
		return false;
	}
	
	return true;
}

bool Shader::CreateShaders()
{
	mVertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (mVertexShaderID == 0)
	{
		std::cout << "[ERR] Error creating vertex shader object." << std::endl;
		return false;
	}

	mFragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (mVertexShaderID == 0)
	{
		std::cout << "[ERR] Error creating fragment shader object." << std::endl;
		return false;
	}

	return true;
}

bool Shader::CompileShaders(const std::string& fileName, ShaderType shaderType)
{
	std::fstream file;
	std::string text;
	std::string sourceCode;

	GLuint shaderID = (shaderType == ShaderType::VERTEX_SHADER) ? mVertexShaderID : mFragmentShaderID;

	file.open(fileName.c_str());
	if (!file)
	{
		std::cout << "[ERR] Error reading shader file: " << fileName << std::endl;
		return false;
	}

	while (!file.eof())
	{
		std::getline(file, text);
		sourceCode += text + "\n";
	}

	file.close();

	const GLchar* finalSourceCode = reinterpret_cast<const GLchar*>(sourceCode.c_str());
	glShaderSource(shaderID, 1, &finalSourceCode, nullptr);

	glCompileShader(shaderID);

	GLint errorCode;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &errorCode);

	if (errorCode == GL_FALSE)
	{
		GLchar errorMessage[1024];
		GLsizei bufferSize = 1024;

		glGetShaderInfoLog(shaderID, bufferSize, &bufferSize, errorMessage);	

		std::cout << "[ERR] " << errorMessage << std::endl;
		return false;
	}

	return true;
}

void Shader::AttachShaders()
{
	glAttachShader(mShaderProgramID, mVertexShaderID);
	glAttachShader(mShaderProgramID, mFragmentShaderID);
}

bool Shader::LinkProgram()
{
	glLinkProgram(mShaderProgramID);
	glUseProgram(mShaderProgramID);

	GLint errorCode;
	glGetProgramiv(mShaderProgramID, GL_LINK_STATUS, &errorCode);

	if (errorCode == GL_FALSE)
	{
		GLchar errorMessage[1024];
		GLsizei bufferSize = 1024;

		glGetProgramInfoLog(mShaderProgramID, bufferSize, &bufferSize, errorMessage);

		std::cout << "[ERR] " << errorMessage << std::endl;
		return false;
	}

	return true;
}

void Shader::DetachShaders()
{
	glDetachShader(mShaderProgramID, mVertexShaderID);
	glDetachShader(mShaderProgramID, mFragmentShaderID);
}

void Shader::DestroyShaders()
{
	glDeleteShader(mVertexShaderID);
	glDeleteShader(mFragmentShaderID);
}

void Shader::DestroyProgram()
{
	glDeleteProgram(mShaderProgramID);
}

bool Shader::SendUniformData(const std::string& uniformName, GLint data)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform1i(ID, data);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLuint data)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform1ui(ID, data);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat data)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform1f(ID, data);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform2f(ID, x, y);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform3f(ID, x, y, z);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniform4f(ID, x, y, z, w);

	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, const glm::mat4& data)
{
	GLint ID = glGetUniformLocation(mShaderProgramID, uniformName.c_str());
	if (ID == -1)
	{
		std::cout << "[ERR] Shader variable " << uniformName << " not used." << std::endl;
		return false;
	}

	glUniformMatrix4fv(ID, 1, GL_FALSE, &data[0][0]);

	return true;
}

