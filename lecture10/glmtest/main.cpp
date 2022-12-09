#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int
main(void) {

	glm::vec3 vec(1.0f, 2.0f, 3.0f);

	fprintf(stdout, "Vector X:%f, Y:%f, Z:%f", vec.x, vec.y, vec.z);
	return 0;
}
