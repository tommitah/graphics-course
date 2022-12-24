#pragma once
#include <glm/glm.hpp>

class Transform {
public:
	glm::mat4 m_translateMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_matrix;

	Transform();
	~Transform();
	void Translate(glm::vec3 p);
	// there's an overload for this in lecture14/scene
	void Rotate(float a, glm::vec3 axis);
	glm::vec3 Forward();
	void UpdateMatrix();

};
