#version 330 core

in vec3 fragmentColor;
in vec2 uv;
out vec3 color;

uniform sampler2D texA;
uniform sampler2D texB;

void main()
{
	// NOTE, changing the textures here in the shader doesn't affect the channels
	// ie. which texture is rendered where
	// color = texture(texA, uv).rgb * texture(texB, uv).rgb * 0.5 + 0.5;
	color = texture(texA, uv).rgb * fragmentColor;
}
