#ifndef INPUT_H
#define INPUT_H

#include <iostream>

#include <SDL.h>

class Input
{
public:
	static Input* Instance();

public:
	bool IsXClicked() const { return mIsXClicked; }
	bool IsKeyPressed() const { return mIsKeyPressed; }

	char GetKeyUp() const { return mKeyUp; }
	char GetKeyDown() const { return mKeyDown; }

	bool IsLeftButtonClicked() const { return mIsLeftButtonClicked; }
	bool IsRightButtonClicked() const { return mIsRightButtonClicked; }
	bool IsMiddleButtonClicked() const { return mIsMiddleButtonClicked; }

	int GetMouseMotionX() const { return mMouseMotionX; }	
	int GetMouseMotionY() const { return mMouseMotionY; }

	int GetMousePositionX() const { return mMousePositionX; }
	int GetMousePositionY() const { return mMousePositionY; }

public:
	void Update();

private:
	Input();
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

private:
	char mKeyUp;
	char mKeyDown;

	bool mIsXClicked;
	bool mIsKeyPressed;

	bool mIsLeftButtonClicked;
	bool mIsRightButtonClicked;
	bool mIsMiddleButtonClicked;

	int mMouseMotionX;
	int mMouseMotionY;

	int mMousePositionX;
	int mMousePositionY;
};

#endif
