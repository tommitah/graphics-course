#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Scene.h"

GLFWwindow* InitWindow() {
	if (!glfwInit()) {
		fprintf(stderr, "GLFW Error.");
		return NULL;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(
		512, 512,
		"Camera",
		NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Window failed.");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		fprintf(stderr, "glad failed.\n");
		glfwTerminate();
		return NULL;
	}

	return window;
}

int main(void)
{
	GLFWwindow* window = InitWindow();
	if (window == NULL) {
		return -1;
	}
	
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Scene scene;
	if (!scene.LoadScene("../scene.scn")) return 0;

	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene.DrawScene();

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	scene.Clear();

	glfwTerminate();
}
