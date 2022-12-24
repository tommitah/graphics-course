#include <fstream>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "Material.h"
#include "shader.hpp"
#include "Scene.h"


Scene::Scene() {
	m_shaderID = LoadShaders("../vertexshader.glsl", "../fragmentshader.glsl");
	m_viewMatrixID = glGetUniformLocation(m_shaderID, "vm");
	m_projectionMatrixID = glGetUniformLocation(m_shaderID, "pm");
}

Scene::~Scene() {
	Clear();
}

// Scene::LoadScene reads a Mesh, Texture and Material from a file,
// initializes the mesh and sets the transform and material for it.
// We could replace or overload this method with a simpler implementation for our
// purposes in this assignment.
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

		Material material( d + "/" + colorTexFile, m_shaderID);
		mesh.SetMaterial(material);

		m_meshes.push_back(mesh);
	}

	file.close();
	printf("Loading done.\n");

	return true;
}

void Scene::DrawScene() {
	glUseProgram(m_shaderID);

	glm::vec3 p(0, 2, 3);
	glm::vec3 r(-0.6, 0, 0);
	m_camera.Translate(p);
	m_camera.Rotate(r);
	m_camera.UpdateMatrix();

	glm::mat4 vm = m_camera.GetViewMatrix();
	glm::mat4 pm = m_camera.GetProjectionMatrix();
	glUniformMatrix4fv(m_viewMatrixID, 1, GL_FALSE, &vm[0][0]);
	glUniformMatrix4fv(m_projectionMatrixID, 1, GL_FALSE, &pm[0][0]);

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
