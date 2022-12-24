#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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


// TODO
// 1. create window DONE
// 2. create mesh for objects
// 3. instantiate objects and show them
// 4. move objects
int main(void)
{
	GLFWwindow* window = InitWindow();
	if (window == NULL) {
		return -1;
	}
	
	printf("In the clear!\n");
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glfwTerminate();
}
