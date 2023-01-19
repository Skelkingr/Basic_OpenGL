#include "Camera.h"

Camera::Camera()
	:
	mView(glm::mat4(1.0f)),
	mPosition(glm::vec3(0.0f)),
	mDirection(glm::vec3(0.0f, 0.0f, -1.0f)),
	mUp(glm::vec3(0.0f, 1.0f, 0.0f))
{}

void Camera::Update()
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
			mPosition.z -= 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 's')
		{
			mPosition.z += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'a')
		{
			mPosition.y += 0.001f;
		}
		else if (Input::Instance()->GetKeyDown() == 'e')
		{
			mPosition.y -= 0.001f;
		}
	}

	mView = glm::lookAt(mPosition, mPosition + mDirection, mUp);
	Shader::Instance()->SendUniformData("view", mView);
}
