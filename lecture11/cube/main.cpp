#include <glm/ext/matrix_transform.hpp>
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"

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
	window = glfwCreateWindow(512, 512, "cube", NULL, NULL);
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
	static const GLfloat vertexBufferData[] = {
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	static const GLfloat colorBufferData[] = {
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(vertexBufferData),
		vertexBufferData,
		GL_STATIC_DRAW);

	GLuint vcb = 0;
	glGenBuffers(1, &vcb);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(colorBufferData),
		colorBufferData,
		GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		0,// vertexshader layout=0 references this parameter
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);
	glVertexAttribPointer(
		1,// shader layout=1
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0);

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
		// 12 * 3 ==> 12 sides in a cube, 3 points for every vertex
		glDrawArrays(GL_TRIANGLES, 0, 12*3);

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0);

	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);
	glfwTerminate();
}
