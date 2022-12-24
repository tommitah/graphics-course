#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Mesh {
public:
	Mesh ();
	~Mesh ();
	void Init(GLuint shader);
	void Clear();
	void DrawMesh();
	void GL_GenerateAndBindBuffers();

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
	
	void Load();
};
