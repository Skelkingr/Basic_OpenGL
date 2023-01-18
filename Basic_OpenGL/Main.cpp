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

	//==========================================================
	
	GLfloat vertices[] = {
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f, 

		-0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f
	};
	
	GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();
	
	GLint vertexID = glGetAttribLocation(shaderProgramID, "position");
	GLint colorID = glGetAttribLocation(shaderProgramID, "color");

	GLuint vertexVBO;
	GLuint colorVBO;
	glGenBuffers(1, &vertexVBO);
	glGenBuffers(1, &colorVBO);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(vertexID, 3, GL_FLOAT, false, 0, nullptr);
		glEnableVertexAttribArray(vertexID);

		glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
		glVertexAttribPointer(colorID, 3, GL_FLOAT, false, 0, nullptr);
		glEnableVertexAttribArray(colorID);

	glBindVertexArray(0);

	//==========================================================

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

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		Screen::Instance()->Present();
	}

	glDeleteBuffers(1, &vertexVBO);
	glDeleteBuffers(1, &colorVBO);
	glDeleteVertexArrays(1, &VAO);

	glDisableVertexAttribArray(vertexID);
	glDisableVertexAttribArray(colorID);

	Shader::Instance()->DetachShaders();
	Shader::Instance()->DestroyShaders();
	Shader::Instance()->DestroyProgram();

	Screen::Instance()->Shutdown();

	return 0;
}