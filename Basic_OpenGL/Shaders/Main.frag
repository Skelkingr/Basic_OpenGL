#version 460 core

in vec3 vs_color;

out vec4 fragColor;

void main()
{
	fragColor = vec4(vs_color, 1.0);
}