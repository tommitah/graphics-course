#version 330 core

layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec2 vertexUV;
layout(location=2) in vec3 vertexNormal;

out vec3 fragmentColor;
out vec2 uv;

uniform mat4 mm;
uniform mat4 vm;
uniform mat4 pm;
uniform mat3 it;
uniform vec3 LightDirection;
uniform float LightAmount;

void main()
{
	gl_Position = pm * vm * mm * vec4(vertexPosition, 1);
	vec3 nor = normalize(it * vertexNormal);
	float nd = max(0.0, dot(nor, LightDirection));
	fragmentColor = vec3(1.0, 1.0, 1.0) * nd * LightAmount;
	uv = vertexUV;
}
