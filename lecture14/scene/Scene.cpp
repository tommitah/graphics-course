#include <fstream>
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
}

Scene::~Scene() {
	Clear();
}

bool Scene::LoadScene(std::string filePath) {
	std::ifstream file(filePath.c_str(), std::ios::in);
	if (!file.is_open()) {
		printf("Scene file can't be loaded!\n");
		return false;
	}

	unsigned int count = 0;
	file.read(reinterpret_cast<char*>(&count), sizeof(count));
	printf("Number of objects: %d \n", count);
	for (unsigned int i = 0; i < count; ++i) {
		// Mesh
		printf("-------\n");
		std::string meshFile;
		unsigned int size = 0;
		file.read(reinterpret_cast<char*>(&size), sizeof(size));
		char* buf = new char[size + 1];
		file.read(buf, size);
		meshFile.append(buf, size);
		delete[] buf;
		printf("Mesh: %s\n", meshFile.c_str());

		// Texture
		std::string colorTexFile;
		size = 0;
		file.read(reinterpret_cast<char*>(&size), sizeof(size));
		buf = new char[size + 1];
		file.read(buf, size);
		colorTexFile.append(buf, size);
		delete[] buf;
		printf("Color texture file: %s\n", colorTexFile.c_str());

		float px = 0.0f;
		file.read(reinterpret_cast<char*>(&px), sizeof(float));
		float py = 0.0f;
		file.read(reinterpret_cast<char*>(&py), sizeof(float));
		float pz = 0.0f;
		file.read(reinterpret_cast<char*>(&pz), sizeof(float));
		printf("\tMesh location: %f, %f, %f\n", px, py, pz);

		float rx = 0.0f;
		file.read(reinterpret_cast<char*>(&rx), sizeof(float));
		float ry = 0.0f;
		file.read(reinterpret_cast<char*>(&ry), sizeof(float));
		float rz = 0.0f;
		file.read(reinterpret_cast<char*>(&rz), sizeof(float));
		printf("\tMesh rotation: %f, %f, %f\n", rx, ry, rz);

		std::string d = filePath.substr(0, filePath.find("/"));
		Mesh mesh;
		// Init loads automagically
		mesh.Init(d + "/" + meshFile, m_shaderID);
		mesh.Translate(glm::vec3(px, py, pz));
	}

	return true;
}

void Scene::DrawScene() {
	glUseProgram(m_shaderID);

	glm::vec3 p(0, 2, 3);
	m_camera.Translate(p);

	glm::vec3 r(-0.6, 0, 0);
	m_camera.Rotate(r);
	m_light.UpdateMatrix();
	m_camera.UpdateMatrix();

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
