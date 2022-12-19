#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Mesh {
public:
	std::string m_file;
	Mesh(std::string file, GLuint shader);
	~Mesh();
	void Clear();
	void DrawMesh();
	void Translate(glm::vec3 position);

private:
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec2> m_uvs;
	std::vector<glm::vec3> m_normals;
	GLuint m_vbo;
	GLuint m_vcb;
	GLuint m_vao;
	GLuint m_modelMatrixID;
	GLuint m_shader;
	glm::mat4 m_translateMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_modelMatrix;

	void Load();
};
