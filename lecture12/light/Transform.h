#pragma once
#include <glm/glm.hpp>

class Transform
{
public:
	glm::mat4 m_translateMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_matrix; // transform matrix

	Transform();
	~Transform();

	void Translate(glm::vec3 position);
	void Rotate(float a, glm::vec3 rotationAxis);
	void UpdateMatrix();
	glm::vec3 Forward();
};
