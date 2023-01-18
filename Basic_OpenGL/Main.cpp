#include <iostream>

#include <Windows.h>
#include <gl/GL.h>

#include "Input.h"
#include "Screen.h"
 
int main(int argc, char* argv[])
{
	bool isAppRunning = true;

	Screen::Instance()->Initialize();

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

		// OLD way of rendering a quad:
		glBegin(GL_QUADS);

			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(xPos - 0.5f, yPos + 0.5f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(xPos + 0.5f, yPos + 0.5f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(xPos + 0.5f, yPos - 0.5f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(xPos - 0.5f, yPos - 0.5f, 0.0f);

		glEnd();

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();

	return 0;
}