#include <glad/glad.h>
#include "objloader.hpp"
#include "mesh.h"

Mesh::Mesh () { }

Mesh::~Mesh () {
	Clear();
}

void Mesh::Init(GLuint shader) {
	// Transform!
	// m_translateMatrix = glm::mat4(1);
	// m_rotationMatrix = glm::mat4(1);

	m_modelMatrixID = glGetUniformLocation(shader, "mm");
	m_itMatrixID = glGetUniformLocation(shader, "it");

	m_shader = shader;
	Load();
}

void Mesh::Clear() {
	m_vertices.clear();
	m_uvs.clear();
	m_normals.clear();

	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_vuv);
	glDeleteBuffers(1, &m_vno);
	glDeleteVertexArrays(1, &m_vao);
}

void Mesh::DrawMesh() {}

void Mesh::GL_GenerateAndBindBuffers() {
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(
		GL_ARRAY_BUFFER,
		m_vertices.size() * sizeof(glm::vec3),
		&m_vertices[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &m_vuv);
	glBindBuffer(GL_ARRAY_BUFFER, m_vuv);
	glBufferData(
		GL_ARRAY_BUFFER,
		m_uvs.size() * sizeof(glm::vec2),
		&m_uvs[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &m_vno);
	glBindBuffer(GL_ARRAY_BUFFER, m_vno);
	glBufferData(
		GL_ARRAY_BUFFER,
		m_normals.size() * sizeof(glm::vec3),
		&m_normals[0],
		GL_STATIC_DRAW);
}

void Mesh::Load() {
	loadOBJ("../bunny.obj", m_vertices, m_uvs, m_normals);
	GL_GenerateAndBindBuffers();

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vuv);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vno);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0);

	// TODO: textures here!
}
