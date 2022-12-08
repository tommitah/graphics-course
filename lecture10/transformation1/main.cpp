#include <glm/ext/matrix_transform.hpp>
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"

long t = 0;

GLFWwindow* InitWindows() {
	if (!glfwInit()) {
		fprintf(stderr, "GLFW Error");
		return NULL;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

GLuint SetVAO() {
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

	return vao;
}

int main() {
	GLFWwindow* window = InitWindows();
	if (window == NULL) {
		fprintf(stderr, "something is terribly wrong");
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	// VAO = Vertex Array Object
	// refactoring like this causes a memory leak since vbo isn't being handled anymore
	GLuint vao = SetVAO();

	// NOTE to self: these are relative paths from the build directory, not this file
	GLuint programID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");

	GLuint modelMatrixID = glGetUniformLocation(programID, "mm");
	GLuint viewMatrixID = glGetUniformLocation(programID, "vm");
	GLuint projectionMatrixID = glGetUniformLocation(programID, "pm");

	glm::mat4 projection = glm::perspective(
			glm::radians(45.0f),
			4.0f/3.0f,
			0.1f,
			100.0f
	);
	glm::mat4 view = glm::lookAt(
			glm::vec3(4, 3, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
	);
	glm::mat4 model = glm::mat4(1);
	glm::mat4 rotation = glm::mat4(1);
	glm::mat4 transformation = glm::mat4(1);

	glUseProgram(programID);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		float z = (float)glm::sin((double)t * 0.1) * 0.1f;
		transformation = glm::translate(transformation, glm::vec3(0.0f, 0.0f, z));
		rotation = glm::rotate(rotation, 0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
		model = transformation * rotation;

		glUniformMatrix4fv(modelMatrixID,		1, GL_FALSE, &model[0][0]);
		glUniformMatrix4fv(viewMatrixID,		1, GL_FALSE, &view[0][0]);
		glUniformMatrix4fv(projectionMatrixID,	1, GL_FALSE, &projection[0][0]);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

		//"time"
		++t;
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0);

	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);
	glfwTerminate();
}
