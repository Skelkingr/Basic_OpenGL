#include "Camera.h"

Camera::Camera()
	:
	m_view(glm::mat4(1.0f)),
	m_proj(glm::mat4(1.0f)),
	m_position(glm::vec3(0.0f)),
	m_direction(glm::vec3(0.0f, 0.0f, -1.0f)),
	m_up(glm::vec3(0.0f, 1.0f, 0.0f))
{}

void Camera::Set3DView()
{
	GLfloat FOV = 45.0f;
	GLfloat aspectRatio = 1280.0f / 720.0f;

	m_proj = glm::perspective(FOV, aspectRatio, 0.001f, 1000.f);
	Shader::Instance()->SendUniformData("proj", m_proj);
}

void Camera::Update()
{
	if (Input::Instance()->IsKeyPressed())
	{
		if (Input::Instance()->GetKeyDown() == 'q')
		{
			m_position.x -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'd')
		{
			m_position.x += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'z')
		{
			m_position.z -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 's')
		{
			m_position.z += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'a')
		{
			m_position.y += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'e')
		{
			m_position.y -= 0.001f;
		}
	}

	m_view = glm::lookAt(m_position, m_position + m_direction, m_up);
	Shader::Instance()->SendUniformData("view", m_view);
}
