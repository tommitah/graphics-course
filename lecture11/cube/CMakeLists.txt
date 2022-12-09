cmake_minimum_required(VERSION 3.25)
# find_package(glfw3 3.3 REQUIRED)

project(lecture11_cube)

add_executable(${PROJECT_NAME} glad.c shader.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
