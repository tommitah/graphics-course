#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "shader.hpp"
#include "Scene.h"

Scene::Scene() {
	// NOTE to self: these are relative paths from the build directory, not this file
	GLuint m_shaderID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");

	GLuint m_viewMatrixID = glGetUniformLocation(m_shaderID, "vm");
	GLuint m_projectionMatrixID = glGetUniformLocation(m_shaderID, "pm");
	GLuint m_lightAmountID = glGetUniformLocation(m_shaderID, "pm");
	GLuint m_lightDirectionID = glGetUniformLocation(m_shaderID, "pm");

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

	m_light.Rotate(glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Scene::~Scene() {
	Clear();
}

void Scene::AddMesh(std::string file) {
	m_meshes.push_back(Mesh());
	m_meshes[(int)m_meshes.size() - 1].Init(file, m_shaderID);
}

void Scene::DrawScene() {
	m_light.UpdateMatrix();
	glUseProgram(m_shaderID);

	glUniformMatrix4fv(m_viewMatrixID, 1, GL_FALSE, &m_viewMatrix[0][0]);
	glUniformMatrix4fv(m_projectionMatrixID, 1, GL_FALSE, &m_projectionMatrix[0][0]);

	glUniform1f(m_lightAmountID, m_light.m_amount);
	glm::vec3 direction = m_light.Forward();
	glUniform3f(m_lightDirectionID, direction.x, direction.y, direction.z);

	for (int i = 0; i < (int)m_meshes.size(); ++i) {
		m_meshes[i].DrawMesh();
	}
}

void Scene::Clear() {
	for (int i = 0; i < (int)m_meshes.size(); ++i) {
		m_meshes[i].Clear();
	}
	m_meshes.clear();
}
