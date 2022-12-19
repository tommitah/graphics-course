#include "Transform.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>

Transform::Transform() {
	m_translateMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::mat4(1.0f);
	m_matrix = glm::mat4(1.0f);
}

Transform::~Transform()
{
}

glm::vec3 Transform::Forward() {
	glm::mat4 t = glm::transpose(m_matrix);
	return glm::vec3(
		t[2][0],
		t[2][1],
		t[2][2]
	);
}

void Transform::Translate(glm::vec3 position) {
	m_translateMatrix = glm::mat4(1.0f);
	m_translateMatrix = glm::translate(m_translateMatrix, position);
}

void Transform::Rotate(float a, glm::vec3 rotationAxis) {
	m_rotationMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::rotate(m_rotationMatrix, a, rotationAxis);
}

void Transform::UpdateMatrix() { m_matrix = m_translateMatrix * m_rotationMatrix; }
