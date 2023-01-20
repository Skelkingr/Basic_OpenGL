#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include <SDL_image.h>

#include "glad.h"

class Texture
{
public:
	Texture();

	void Bind();
	bool Load(const std::string& fileName);
	void Unbind();
	void Unload();

private:
	GLuint m_ID;
};

#endif

