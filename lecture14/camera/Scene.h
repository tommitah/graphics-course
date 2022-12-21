#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Light.h"

class Scene {
public:
	Scene(); 
	~Scene();
	void AddMesh(std::string file);
	void DrawScene();
	void Clear();

private:
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
	GLuint m_viewMatrixID;
	GLuint m_projectionMatrixID;
	GLuint m_shaderID;
	GLuint m_lightAmountID;
	GLuint m_lightDirectionID;
	std::vector<Mesh> m_meshes;
	Light m_light;
};

