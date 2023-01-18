#include "Quad.h"

Quad::Quad()
	:
	mModelMatrix(glm::mat4(1.0f)),
	mPosition(glm::vec3(0.0f))
{
	GLfloat vertices[] = {
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,

		-0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f
	};

	mBuffer = Buffer();

	mBuffer.CreateBuffer(6);
	mBuffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
	mBuffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);

	mBuffer.LinkBuffer("position", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
	mBuffer.LinkBuffer("color", Buffer::COLOR_BUFFER, Buffer::XYZ, Buffer::FLOAT);
}

Quad::Quad(GLfloat width, GLfloat height)
	:
	mPosition(glm::vec3(0.0f))
{
	mModelMatrix = glm::mat4(1.0f);

	GLfloat halfWidth = width * 0.5f;
	GLfloat halfHeight = height * 0.5f;

	GLfloat vertices[] = {
		-halfWidth,  halfHeight, 0.0f,
		 halfWidth,  halfHeight, 0.0f,
		-halfWidth, -halfHeight, 0.0f,

		-halfWidth, -halfHeight, 0.0f,
		 halfWidth,  halfHeight, 0.0f,
		 halfWidth, -halfHeight, 0.0f
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f
	};

	mBuffer = Buffer();

	mBuffer.CreateBuffer(6);
	mBuffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
	mBuffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);

	mBuffer.LinkBuffer("position", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
	mBuffer.LinkBuffer("color", Buffer::COLOR_BUFFER, Buffer::XYZ, Buffer::FLOAT);
}

Quad::~Quad()
{
	mBuffer.DestroyBuffer();
}

void Quad::Update()
{
	if (Input::Instance()->IsKeyPressed())
	{
		if (Input::Instance()->GetKeyDown() == 'q')
		{
			mPosition.x -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'd')
		{
			mPosition.x += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'z')
		{
			mPosition.y += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 's')
		{
			mPosition.y -= 0.001f;
		}
	}

	mModelMatrix = glm::mat4(1.0f);
	mModelMatrix = glm::translate(mModelMatrix, mPosition);
}

void Quad::Render()
{
	Shader::Instance()->SendUniformData("model", mModelMatrix);
	mBuffer.Render(Buffer::TRIANGLES);
}
