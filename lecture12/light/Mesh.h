#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Transform.h"

class Mesh : public Transform {
public:
	std::string m_file;
	Mesh();
	~Mesh();
	void Init(std::string file, GLuint shader);
	void Clear();
	void DrawMesh();

private:
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_normals;
	std::vector<glm::vec2> m_uvs;
	GLuint m_vbo;
	GLuint m_vuv;
	GLuint m_vno;
	GLuint m_vao;
	GLuint m_modelMatrixID;
	GLuint m_itMatrixID; //inverse transpose matrix
	GLuint m_shader;

	void Load();
};
