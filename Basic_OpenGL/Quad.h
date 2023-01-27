#ifndef QUAD_H
#define QUAD_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Buffer.h"
#include "glad.h"
#include "Input.h"
#include "Shader.h"
#include "Texture.h"

class Quad
{
public:
	Quad();
	Quad(GLfloat width, GLfloat height);
	~Quad();

	void Update();
	void Render();

private:
	Buffer m_buffer;
	Texture m_texture;

	glm::mat4 m_model;
	glm::vec3 m_position;

	float m_shininess;
	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;
};

#endif