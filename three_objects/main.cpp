#include <stdio.h>
#include "window.h"

// TODO
// 1. create window DONE
// 1.5 separate initwindow from main DONE
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
