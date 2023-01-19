#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "glad.h"
#include "Input.h"
#include "Shader.h"

class Camera
{
public:
	Camera();

	void Update();

protected:
	glm::mat4 mView;

	glm::vec3 mPosition;
	glm::vec3 mDirection;
	glm::vec3 mUp;
};

#endif

