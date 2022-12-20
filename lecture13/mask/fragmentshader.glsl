#version 330 core

in vec3 fragmentColor;
in vec2 uv;

out vec3 color;

uniform sampler2D texA;
uniform sampler2D texB;
uniform sampler2D texM;

void main()
{
	float v = texture(texM, uv).r;
	color = mix(texture(texA, uv).rgb, texture(texB, uv).rgb, v);
}
