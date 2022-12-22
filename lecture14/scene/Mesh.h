#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Material.h"

#include <GLFW/glfw3.h>

class Mesh : public Transform {
public:
	std::string m_file;
	Mesh();
	~Mesh();
	void Init(std::string file, GLuint shader);
	void Clear();
	void GL_GenerateAndBindBuffers();
	void DrawMesh();
	void SetMaterial(Material m);

private:
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec2> m_uvs;
	std::vector<glm::vec3> m_normals;
	GLuint m_vbo;
	GLuint m_vuv;
	GLuint m_vno;
	GLuint m_vao;
	GLuint m_modelMatrixID;
	GLuint m_itMatrixID;
	GLuint m_shader;
	Material m_material;

	void Load();
};

