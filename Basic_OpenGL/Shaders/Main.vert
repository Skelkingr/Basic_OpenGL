#version 460 core

in vec3 position;
in vec3 color;
in vec2 tex;

out vec3 vs_vertex;
out vec3 vs_color;
out vec2 vs_tex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * model * vec4(position, 1.0);

	vs_vertex = (model * vec4(position, 1.0)).xyz;
	vs_color = color;
	vs_tex = tex;
}

