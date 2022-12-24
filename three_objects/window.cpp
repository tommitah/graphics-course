#include <stdio.h>
#include "window.h"

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
		"Three objects",
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
