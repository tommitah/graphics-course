#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

void init_glfw() {
	if (!glfwInit()) {
		fprintf(stderr, "GLFW Error");
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* init_windows() {
	init_glfw();

	GLFWwindow* window;
	window = glfwCreateWindow(512, 512, "triangle", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "window failed");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		fprintf(stderr, "glad init failed");
		glfwTerminate();
		return NULL;
	}
	
	return window;
}

int main() {
	GLFWwindow* window = init_windows();
	if (window == NULL) {
		fprintf(stderr, "something is terribly wrong");
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	static const GLfloat vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(vertex_buffer_data),
			vertex_buffer_data,
			GL_STATIC_DRAW
	);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
	);
	glEnableVertexAttribArray(0);

	// NOTE to self: these are relative paths from the build directory, not this file
	GLuint programID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");
	glUseProgram(programID);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glfwTerminate();
}
