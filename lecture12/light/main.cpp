#include <glm/ext/matrix_transform.hpp>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "objloader.hpp"
#include "Mesh.h"

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
	window = glfwCreateWindow(512, 512, "Loader", NULL, NULL);
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

int main(void) {
	GLFWwindow* window = InitWindows();
	if (window == NULL) {
		fprintf(stderr, "something is terribly wrong");
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// NOTE to self: these are relative paths from the build directory, not this file
	GLuint programID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");

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

	Mesh meshes[2] = {
		Mesh("../bunny.obj", programID),
		Mesh("../dino.obj", programID),
	};

	meshes[0].Translate(glm::vec3(-1, 0, 0));
	meshes[1].Translate(glm::vec3(1, 0, 0));

	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glUseProgram(programID);
		glUniformMatrix4fv(viewMatrixID,		1, GL_FALSE, &view[0][0]);
		glUniformMatrix4fv(projectionMatrixID,	1, GL_FALSE, &projection[0][0]);

		for(int i=0; i < 2; ++i) {
			meshes[i].DrawMesh();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0);

	for(int i=0; i < 2; ++i) {
		meshes[i].Clear();
	}

	glDeleteProgram(programID);

	glfwTerminate();
}
