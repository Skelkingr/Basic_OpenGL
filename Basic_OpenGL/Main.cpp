#include <iostream>

#include "Input.h"
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

	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();

		Input::Instance()->Update();

		char keyPressed = Input::Instance()->GetKeyDown();

		isAppRunning = !Input::Instance()->IsXClicked();

		if (Input::Instance()->IsKeyPressed())
		{
			if (Input::Instance()->GetKeyDown() == 'q')
			{
				xPos -= 0.001f;
			}
			else if (Input::Instance()->GetKeyDown() == 'd')
			{
				xPos += 0.001f;
			}
			else if (Input::Instance()->GetKeyDown() == 'z')
			{
				yPos += 0.001f;
			}
			else if (Input::Instance()->GetKeyDown() == 's')
			{
				yPos -= 0.001f;
			}
		}

		Screen::Instance()->Present();
	}

	Shader::Instance()->DetachShaders();
	Shader::Instance()->DestroyShaders();
	Shader::Instance()->DestroyProgram();

	Screen::Instance()->Shutdown();

	return 0;
}