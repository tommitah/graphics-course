#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/trigonometric.hpp>
#include "Camera.h"

Camera::Camera() {
	m_projectionMatrix = glm::perspective(
			glm::radians(65.0f),
			4.0f/3.0f,
			0.1f,
			100.0f
	);
	
	m_viewMatrix = glm::mat4(1.0f); //identity matrix
}

Camera::~Camera() {}

void Camera::UpdateMatrix() {
	Transform::UpdateMatrix();

	// if the view matrix is not 'inversed',
	// the camera won't be looking at the object
	// which is why this can't just use the normal Transform::UpdateMatrix()
	m_viewMatrix = glm::inverse(m_matrix);
}

glm::mat4& Camera::GetViewMatrix() { return m_viewMatrix; }
glm::mat4& Camera::GetProjectionMatrix() { return m_projectionMatrix; }
