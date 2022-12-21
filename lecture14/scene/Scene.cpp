#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "shader.hpp"
#include "Scene.h"


Scene::Scene() {
	m_shaderID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");
	m_viewMatrixID = glGetUniformLocation(m_shaderID, "vm");
	m_projectionMatrixID = glGetUniformLocation(m_shaderID, "pm");
	m_lightAmountID = glGetUniformLocation(m_shaderID, "LightAmount");
	m_lightDirectionID = glGetUniformLocation(m_shaderID, "LightDirection");

	m_light.Rotate(glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0));
	m_camera.Translate(glm::vec3(0, 0.5, 2.0));
}

Scene::~Scene() {
	Clear();
}

void Scene::AddMesh(std::string file) {
	m_meshes.push_back(Mesh());

	// -1 so we don't get don't seg fault here
	m_meshes[(int)m_meshes.size() - 1].Init(file, m_shaderID);
}

void Scene::DrawScene() {
	double t = glfwGetTime();
	glm::vec3 p(0, glm::sin(t), 5);
	m_camera.Translate(p);

	m_light.UpdateMatrix();
	m_camera.UpdateMatrix();

	glUseProgram(m_shaderID);

	glm::mat4 vm = m_camera.GetViewMatrix();
	glm::mat4 pm = m_camera.GetProjectionMatrix();
	glUniformMatrix4fv(m_viewMatrixID, 1, GL_FALSE, &vm[0][0]);
	glUniformMatrix4fv(m_projectionMatrixID, 1, GL_FALSE, &pm[0][0]);

	glUniform1f(m_lightAmountID, m_light.m_amount);
	glm::vec3 d = m_light.Forward();
	glUniform3f(m_lightDirectionID, d.x, d.y, d.z);
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
