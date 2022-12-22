#version 330 core

in vec3 fragmentColor;
in vec2 uv;
out vec3 color;

uniform sampler2D colorTex;

void main()
{
	color = texture(colorTex, uv).rgb;
}
