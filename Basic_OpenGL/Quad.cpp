#include "Quad.h"

Quad::Quad()
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

Quad::~Quad()
{
	mBuffer.DestroyBuffer();
}

void Quad::Render()
{
	mBuffer.Render(Buffer::TRIANGLES);
}
