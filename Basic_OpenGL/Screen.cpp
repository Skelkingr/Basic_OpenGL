#include "Screen.h"

Screen::Screen()
	:
	mWindow(nullptr),
	mContext(nullptr)
{}

Screen* Screen::Instance()
{
	static Screen* screen = new Screen();
	return screen;
}

bool Screen::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "[ERR] Error initializing SDL." << std::endl;
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	mWindow = SDL_CreateWindow(
		"Skelkingr",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL
	);

	if (!mWindow)
	{
		std::cout << "[ERR] Error creating SDL mWindow." << std::endl;
		return false;
	}

	mContext = SDL_GL_CreateContext(mWindow);

	if (!mContext)
	{
		std::cout << "[ERR] Error creating OpenGL mContext." << std::endl;
		return false;
	}

	if (!gladLoadGL())
	{
		std::cout << "[ERR] Error loading extensions." << std::endl;
		return false;
	}

    return true;
}

void Screen::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::Present()
{
	SDL_GL_SwapWindow(mWindow);
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(mContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

