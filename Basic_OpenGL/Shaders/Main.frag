#version 460 core

in vec3 vs_color;
in vec2 vs_tex;

out vec4 fragColor;

uniform bool isLit;
uniform bool isTextured;

uniform sampler2D textureImg;

void main()
{
	fragColor = vec4(vs_color, 1.0) * texture(textureImg, vs_tex);
}