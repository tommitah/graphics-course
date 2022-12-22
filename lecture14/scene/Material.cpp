#include "Material.h"
#include "texture.hpp"

Material::Material() {}

Material::Material(std::string colorTexFile, GLuint shader) {
	printf("Create material. \n");
	printf("\tLoad texture %s", colorTexFile.c_str());
	m_colorTex = loadDDS(colorTexFile.c_str());

	m_shader = shader;
	printf("Shader id: %d\n", m_shader);

	m_colorTexID = glGetUniformLocation(m_shader, "colorTex");
}

Material::~Material() {}

void Material::Clear() {
	glDeleteTextures(1, &m_colorTex);
}
