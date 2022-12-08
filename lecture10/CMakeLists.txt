cmake_minimum_required(VERSION 3.25)
# find_package(glfw3 3.3 REQUIRED)

project(lecture10_tranformations)

add_executable(${PROJECT_NAME} glad.c main.cpp)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
