#include <iostream>

#include <Windows.h>
#include <gl/GL.h>

#include "Screen.h"

bool isAppRunning = true;

int main(int argc, char* argv[])
{
	Screen::Instance()->Initialize();

	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();

		/*glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);

		glEnd();*/

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();

	system("pause");
	return 0;
}