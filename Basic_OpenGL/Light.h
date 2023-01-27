#ifndef LIGHT_H
#define LIGHT_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Buffer.h"
#include "Input.h"
#include "Shader.h"

class Light
{
public:
	Light();
	~Light();

	void Update();
	void Render();
	void SendToShader();

private:
	Buffer m_buffer;

	glm::mat4 m_model;
	glm::vec3 m_position;

	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;
};

#endif
