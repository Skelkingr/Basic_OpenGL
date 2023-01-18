#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

#include <Windows.h>
#include <SDL.h>

#include "glad.h"

class Screen
{
public:
	static Screen* Instance();

public:
	bool Initialize();
	void ClearScreen();
	void Present();
	void Shutdown();

private:
	Screen();
	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;

private:
	SDL_Window* mWindow;
	SDL_GLContext mContext;
};

#endif

