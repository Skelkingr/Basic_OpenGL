#include "Quad.h"

Quad::Quad()
	:
	mModel(glm::mat4(1.0f)),
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
	mModel = glm::mat4(1.0f);

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
		if (Input::Instance()->GetKeyDown() == 'j')
		{
			mPosition.x -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'l')
		{
			mPosition.x += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'i')
		{
			mPosition.z -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'k')
		{
			mPosition.z += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'u')
		{
			mPosition.y += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'o')
		{
			mPosition.y -= 0.001f;
		}
	}

	mModel = glm::mat4(1.0f);
	mModel = glm::translate(mModel, mPosition);
}

void Quad::Render()
{
	Shader::Instance()->SendUniformData("model", mModel);
	mBuffer.Render(Buffer::TRIANGLES);
}
