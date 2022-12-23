#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "Transform.h"

Transform::Transform()
{
    m_translateMatrix = glm::mat4(1.0f);
    m_rotationMatrix = glm::mat4(1.0f);
    m_matrix = glm::mat4(1.0f);
}

Transform::~Transform()
{
}

void Transform::Translate(glm::vec3 p)
{
    m_translateMatrix = glm::mat4(1.0f);
    m_translateMatrix = glm::translate(m_translateMatrix, p);
}

void Transform::Rotate(float a, glm::vec3 axis)
{
    m_rotationMatrix = glm::mat4(1.0f);
    m_rotationMatrix = glm::rotate(m_rotationMatrix, a, axis);
}

void Transform::Rotate(glm::vec3 euler)
{
    m_rotationMatrix = glm::mat4(1.0f);
    m_rotationMatrix = glm::eulerAngleXYZ(euler.x, euler.y, euler.z);
}

glm::vec3 Transform::Forward()
{
    glm::mat4 t = glm::transpose(m_matrix);
    return glm::vec3(
        t[2][0],
        t[2][1],
        t[2][2]);
}

void Transform::UpdateMatrix()
{
    m_matrix = m_translateMatrix * m_rotationMatrix;
}
