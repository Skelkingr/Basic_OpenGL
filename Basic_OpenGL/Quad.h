#ifndef QUAD_H
#define QUAD_H

#include "Buffer.h"
#include "glad.h"
#include "Shader.h"

class Quad
{
public:
	Quad();
	~Quad();

	void Render();

private:
	Buffer mBuffer;
};

#endif