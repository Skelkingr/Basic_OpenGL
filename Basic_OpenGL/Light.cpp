#include "Light.h"

Light::Light()
	:
	m_model(glm::mat4(1.0f)),
	m_ambient(glm::vec3(1.0f)),
	m_diffuse(glm::vec3(1.0f)),
	m_specular(glm::vec3(1.0f))
{
	m_position = glm::vec3(0.0f, 4.0f, 0.0f);

	GLfloat vertices[] = { 0.0f, 0.0f, 0.0f };
	GLfloat colors[] = { 1.0f, 1.0f, 1.0f };

	m_buffer.CreateBuffer(1);

	m_buffer.FillVBO(Buffer::VERTEX_BUFFER, vertices, sizeof(vertices), Buffer::SINGLE);
	m_buffer.FillVBO(Buffer::COLOR_BUFFER, colors, sizeof(colors), Buffer::SINGLE);

	m_buffer.LinkBuffer("position", Buffer::VERTEX_BUFFER, Buffer::XYZ, Buffer::FLOAT);
	m_buffer.LinkBuffer("color", Buffer::COLOR_BUFFER, Buffer::RGB, Buffer::FLOAT);
}

Light::~Light()
{
	m_buffer.DestroyBuffer();
}

void Light::Update()
{
	//TODO
}

void Light::Render()
{
	Shader::Instance()->SendUniformData("model", m_model);
	Shader::Instance()->SendUniformData("isLit", false);
	Shader::Instance()->SendUniformData("isTextured", false);

	m_buffer.Render(Buffer::POINTS);
}

void Light::SendToShader()
{
	//TODO
}
