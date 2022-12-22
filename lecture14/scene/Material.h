#pragma once
#include <glad/glad.h>
#include <string>

class Material {
public:
	GLuint m_colorTex;
	GLuint m_colorTexID;
	Material();
	Material(std::string colorTexFile, GLuint shader);
	~Material();
	void Clear();

private:
	GLuint m_shader;
};
