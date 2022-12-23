#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Light.h"
#include "Camera.h"

class Scene {
public:
	Scene(); 
	~Scene();
	bool LoadScene(std::string file);
	void DrawScene();
	void Clear();

private:
	GLuint m_viewMatrixID;
	GLuint m_projectionMatrixID;
	GLuint m_shaderID;
	GLuint m_lightAmountID;
	GLuint m_lightDirectionID;
	std::vector<Mesh> m_meshes;
	Light m_light;
	Camera m_camera;
};

