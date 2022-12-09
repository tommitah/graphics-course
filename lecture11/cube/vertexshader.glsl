#version 330 core

layout(location=0) in vec3 vertexPosition_modelspace;

uniform mat4 mm;
uniform mat4 vm;
uniform mat4 pm;

void main()
{
	gl_Position = pm * vm * mm * vec4(vertexPosition_modelspace, 1);
}
