#include "Buffer.h"

Buffer::Buffer()
	:
	mVAO(0),
	mVertexVBO(0),
	mColorVBO(0),
	mTotalVertices(0)
{}

void Buffer::CreateBuffer(GLuint totalVertices)
{
	glGenBuffers(1, &mVertexVBO);
	glGenBuffers(1, &mColorVBO);

	glGenVertexArrays(1, &mVAO);

	mTotalVertices = totalVertices;
}

void Buffer::FillVBO(VBOType vboType, GLfloat* data, GLsizeiptr bufferSize, FillType fillType)
{
	glBindVertexArray(mVAO);

		if (vboType == VERTEX_BUFFER)
		{
			glBindBuffer(GL_ARRAY_BUFFER, mVertexVBO);
		}
		else if (vboType == COLOR_BUFFER)
		{
			glBindBuffer(GL_ARRAY_BUFFER, mColorVBO);
		}

		glBufferData(GL_ARRAY_BUFFER, bufferSize, data, fillType);

	glBindVertexArray(0);
}

void Buffer::LinkBuffer(const std::string& attribute, VBOType vboType, ComponentType componentType, DataType dataType)
{
	GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();

	GLint ID = glGetAttribLocation(shaderProgramID, attribute.c_str());

	glBindVertexArray(mVAO);

		if (vboType == VERTEX_BUFFER)
		{
			glBindBuffer(GL_ARRAY_BUFFER, mVertexVBO);
		}
		else if (vboType == COLOR_BUFFER)
		{
			glBindBuffer(GL_ARRAY_BUFFER, mColorVBO);
		}

		glVertexAttribPointer(ID, componentType, dataType, false, 0, nullptr);
		glEnableVertexAttribArray(ID);

	glBindVertexArray(0);
}

void Buffer::Render(DrawType drawType)
{
	glBindVertexArray(mVAO);
	glDrawArrays(drawType, 0, mTotalVertices);
	glBindVertexArray(0);
}

void Buffer::DestroyBuffer()
{
	glDeleteBuffers(1, &mVertexVBO);
	glDeleteBuffers(1, &mColorVBO);
	glDeleteVertexArrays(1, &mVAO);	
}
