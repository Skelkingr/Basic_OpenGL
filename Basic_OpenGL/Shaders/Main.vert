#version 460 core

in vec3 position;
in vec3 color;

out vec3 vs_color;

uniform mat4 model;
uniform mat4 view;

void main()
{
	gl_Position = view * model * vec4(position, 1.0);

	vs_color = color;
}

