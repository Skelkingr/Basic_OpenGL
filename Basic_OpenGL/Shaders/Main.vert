#version 460 core

in vec3 position;
in vec3 color;

out vec3 vs_color;

uniform mat4 model;

void main()
{
	gl_Position = model * vec4(position, 1.0);

	vs_color = color;
}

