#include <glm/ext/matrix_transform.hpp>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "objloader.hpp"

int vertexCount = 0;

GLFWwindow*
InitWindows() {
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

GLuint
SetVAO() {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	loadOBJ("../bunny.obj", vertices, uvs, normals);

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
			GL_ARRAY_BUFFER,
			vertices.size() * sizeof(glm::vec3),
			&vertices[0],
			GL_STATIC_DRAW
	);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
			0,// shader index
			3,// amount
			GL_FLOAT, // type
			GL_FALSE, // not normalized
			0,
			(void*)0
	);

	vertexCount = vertices.size();

	return vao;
}

int
main() {
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

	glUseProgram(programID);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		glUniformMatrix4fv(modelMatrixID,		1, GL_FALSE, &model[0][0]);
		glUniformMatrix4fv(viewMatrixID,		1, GL_FALSE, &view[0][0]);
		glUniformMatrix4fv(projectionMatrixID,	1, GL_FALSE, &projection[0][0]);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertexCount);

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0);

	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);
	glfwTerminate();
}
