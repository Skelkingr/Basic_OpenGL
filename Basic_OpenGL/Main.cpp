#include <iostream>

#include "Camera.h"
#include "Input.h"
#include "Light.h"
#include "Quad.h"
#include "Shader.h"
#include "Screen.h"
 
int main(int argc, char* argv[])
{
	bool isAppRunning = true;

	Screen::Instance()->Initialize();

	Shader::Instance()->CreateProgram();
	Shader::Instance()->CreateShaders();

	Shader::Instance()->CompileShaders("Shaders\\Main.vert", Shader::ShaderType::VERTEX_SHADER);
	Shader::Instance()->CompileShaders("Shaders\\Main.frag", Shader::ShaderType::FRAGMENT_SHADER);

	Shader::Instance()->AttachShaders();	
	Shader::Instance()->LinkProgram();

	float xPos = 0.0f;
	float yPos = 0.0f;

	//==========================================================
	Camera camera;
	camera.Set3DView();

	Quad quad;

	Light light;
	//==========================================================

	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();

		Input::Instance()->Update();

		char keyPressed = Input::Instance()->GetKeyDown();

		isAppRunning = !Input::Instance()->IsXClicked();

		camera.Update();

		light.Update();
		light.Render();
		light.SendToShader();

		quad.Update();
		quad.Render();

		Screen::Instance()->Present();
	}

	Shader::Instance()->DetachShaders();
	Shader::Instance()->DestroyShaders();
	Shader::Instance()->DestroyProgram();

	Screen::Instance()->Shutdown();

	return 0;
}