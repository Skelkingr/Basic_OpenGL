#include "Quad.h"

Quad::Quad()
	:
	m_model(glm::mat4(1.0f)),
	m_position(glm::vec3(0.0f, 0.0f, -2.0f))
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
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
			  		
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};

	GLfloat textureUVs[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	m_buffer = Buffer();

	m_buffer.CreateBuffer(6);
	m_buffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
	m_buffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);
	m_buffer.FillVBO(Buffer::TEXTURE_BUFFER, textureUVs, sizeof(textureUVs), Buffer::SINGLE);

	m_buffer.LinkBuffer("position", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
	m_buffer.LinkBuffer("color", Buffer::COLOR_BUFFER, Buffer::RGB, Buffer::FLOAT);
	m_buffer.LinkBuffer("tex", Buffer::TEXTURE_BUFFER, Buffer::UV, Buffer::FLOAT);

	m_texture.Load("Textures\\Crate_1.png");
}

Quad::Quad(GLfloat width, GLfloat height)
	:
	m_model(glm::mat4(1.0f)),
	m_position(glm::vec3(0.0f, 0.0f, -2.0f))
{
	m_model = glm::mat4(1.0f);

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
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};

	GLfloat textureUVs[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	m_buffer = Buffer();

	m_buffer.CreateBuffer(6);
	m_buffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
	m_buffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);
	m_buffer.FillVBO(Buffer::TEXTURE_BUFFER, textureUVs, sizeof(textureUVs), Buffer::SINGLE);

	m_buffer.LinkBuffer("position", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
	m_buffer.LinkBuffer("color", Buffer::COLOR_BUFFER, Buffer::RGB, Buffer::FLOAT);
	m_buffer.LinkBuffer("tex", Buffer::TEXTURE_BUFFER, Buffer::UV, Buffer::FLOAT);

	m_texture.Load("Textures\\Crate_1.png");
}

Quad::~Quad()
{
	m_buffer.DestroyBuffer();
}

void Quad::Update()
{
	if (Input::Instance()->IsKeyPressed())
	{
		if (Input::Instance()->GetKeyDown() == 'j')
		{
			m_position.x -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'l')
		{
			m_position.x += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'i')
		{
			m_position.z -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'k')
		{
			m_position.z += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'u')
		{
			m_position.y += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'o')
		{
			m_position.y -= 0.001f;
		}
	}

	m_model = glm::mat4(1.0f);
	m_model = glm::translate(m_model, m_position);
}

void Quad::Render()
{
	Shader::Instance()->SendUniformData("model", m_model);

	m_texture.Bind();
	m_buffer.Render(Buffer::TRIANGLES);
	m_texture.Unbind();
}
