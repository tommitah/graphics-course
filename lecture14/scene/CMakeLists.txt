cmake_minimum_required(VERSION 3.25)

project(lecture14_scene)

add_executable(${PROJECT_NAME} glad.c shader.cpp objloader.cpp Transform.cpp Scene.cpp Mesh.cpp Light.cpp texture.cpp Camera.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
