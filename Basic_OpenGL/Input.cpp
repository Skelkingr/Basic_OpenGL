#include "Input.h"

Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}

Input::Input()
	:
	mKeyUp(0),
	mKeyDown(0),
	mIsXClicked(false),
	mIsKeyPressed(false),
	mIsLeftButtonClicked(false),
	mIsRightButtonClicked(false),
	mIsMiddleButtonClicked(false),
	mMouseMotionX(0),
	mMouseMotionY(0),
	mMousePositionX(0),
	mMousePositionY(0)
{}

void Input::Update()
{
	SDL_Event events;

	mMouseMotionX = 0;
	mMouseMotionY = 0;

	mMousePositionX = 0;
	mMousePositionY = 0;

	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
			case SDL_QUIT:
			{
				mIsXClicked = true;
				break;
			}

			case SDL_KEYDOWN:
			{
				mIsKeyPressed = true;
				mKeyDown = events.key.keysym.sym;
				break;
			}

			case SDL_KEYUP:
			{
				mIsKeyPressed = false;
				mKeyUp = events.key.keysym.sym;
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				switch (events.button.button)
				{
					case SDL_BUTTON_LEFT:
					{
						mIsLeftButtonClicked = true;
						break;
					}
					case SDL_BUTTON_RIGHT:
					{
						mIsRightButtonClicked = true;
						break;
					}
					case SDL_BUTTON_MIDDLE:
					{
						mIsMiddleButtonClicked = true;
						break;
					}
				}
				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				switch (events.button.button)
				{
					case SDL_BUTTON_LEFT:
					{
						mIsLeftButtonClicked = false;
						break;
					}
					case SDL_BUTTON_RIGHT:
					{
						mIsRightButtonClicked = false;
						break;
					}
					case SDL_BUTTON_MIDDLE:
					{
						mIsMiddleButtonClicked = false;
						break;
					}
				}
				break;
			}

			case SDL_MOUSEMOTION:
			{
				mMouseMotionX = events.motion.xrel;
				mMouseMotionY = events.motion.yrel;

				mMousePositionX = events.motion.x;
				mMousePositionY = events.motion.y;

				break;
			}
		}
	}
}

