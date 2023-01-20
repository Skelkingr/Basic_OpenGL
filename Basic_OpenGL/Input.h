#ifndef INPUT_H
#define INPUT_H

#include <iostream>

#include <SDL.h>

class Input
{
public:
	static Input* Instance();

public:
	bool IsXClicked() const { return m_isXClicked; }
	bool IsKeyPressed() const { return m_isKeyPressed; }

	char GetKeyUp() const { return m_keyUp; }
	char GetKeyDown() const { return m_keyDown; }

	bool IsLeftButtonClicked() const { return m_isLeftButtonClicked; }
	bool IsRightButtonClicked() const { return m_isRightButtonClicked; }
	bool IsMiddleButtonClicked() const { return m_isMiddleButtonClicked; }

	int GetMouseMotionX() const { return m_mouseMotionX; }	
	int GetMouseMotionY() const { return m_mouseMotionY; }

	int GetMousePositionX() const { return m_mousePositionX; }
	int GetMousePositionY() const { return m_mousePositionY; }

public:
	void Update();

private:
	Input();
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

private:
	char m_keyUp;
	char m_keyDown;

	bool m_isXClicked;
	bool m_isKeyPressed;

	bool m_isLeftButtonClicked;
	bool m_isRightButtonClicked;
	bool m_isMiddleButtonClicked;

	int m_mouseMotionX;
	int m_mouseMotionY;

	int m_mousePositionX;
	int m_mousePositionY;
};

#endif
