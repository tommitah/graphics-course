cmake_minimum_required(VERSION 3.25)

project(three_objects)

add_executable(${PROJECT_NAME}
	glad.c
	window.cpp
	# shader.cpp
	objloader.cpp
	transform.cpp
	# Scene.cpp
	mesh.cpp
	# Light.cpp
	# texture.cpp
	# Camera.cpp
	main.cpp)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
