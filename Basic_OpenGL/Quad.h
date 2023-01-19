#ifndef QUAD_H
#define QUAD_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Buffer.h"
#include "glad.h"
#include "Input.h"
#include "Shader.h"

class Quad
{
public:
	Quad();
	Quad(GLfloat width, GLfloat height);
	~Quad();

	void Update();
	void Render();

private:
	Buffer mBuffer;
	glm::mat4 mModel;
	glm::vec3 mPosition;
};

#endif