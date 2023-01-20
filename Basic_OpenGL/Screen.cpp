#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screen = new Screen();
	return screen;
}
Screen::Screen()
	:
	m_window(nullptr),
	m_context(nullptr)
{}

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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	m_window = SDL_CreateWindow(
		"Skelkingr",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL
	);

	if (!m_window)
	{
		std::cout << "[ERR] Error creating SDL m_window." << std::endl;
		return false;
	}

	m_context = SDL_GL_CreateContext(m_window);

	if (!m_context)
	{
		std::cout << "[ERR] Error creating OpenGL m_context." << std::endl;
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
	SDL_GL_SwapWindow(m_window);
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

