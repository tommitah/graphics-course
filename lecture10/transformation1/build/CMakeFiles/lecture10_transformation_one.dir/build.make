# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tommitah/development/graphics-course/lecture10/transformation1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tommitah/development/graphics-course/lecture10/transformation1/build

# Include any dependencies generated for this target.
include CMakeFiles/lecture10_transformation_one.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lecture10_transformation_one.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lecture10_transformation_one.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lecture10_transformation_one.dir/flags.make

CMakeFiles/lecture10_transformation_one.dir/glad.c.o: CMakeFiles/lecture10_transformation_one.dir/flags.make
CMakeFiles/lecture10_transformation_one.dir/glad.c.o: /home/tommitah/development/graphics-course/lecture10/transformation1/glad.c
CMakeFiles/lecture10_transformation_one.dir/glad.c.o: CMakeFiles/lecture10_transformation_one.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommitah/development/graphics-course/lecture10/transformation1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lecture10_transformation_one.dir/glad.c.o"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lecture10_transformation_one.dir/glad.c.o -MF CMakeFiles/lecture10_transformation_one.dir/glad.c.o.d -o CMakeFiles/lecture10_transformation_one.dir/glad.c.o -c /home/tommitah/development/graphics-course/lecture10/transformation1/glad.c

CMakeFiles/lecture10_transformation_one.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lecture10_transformation_one.dir/glad.c.i"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tommitah/development/graphics-course/lecture10/transformation1/glad.c > CMakeFiles/lecture10_transformation_one.dir/glad.c.i

CMakeFiles/lecture10_transformation_one.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lecture10_transformation_one.dir/glad.c.s"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tommitah/development/graphics-course/lecture10/transformation1/glad.c -o CMakeFiles/lecture10_transformation_one.dir/glad.c.s

CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o: CMakeFiles/lecture10_transformation_one.dir/flags.make
CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o: /home/tommitah/development/graphics-course/lecture10/transformation1/shader.cpp
CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o: CMakeFiles/lecture10_transformation_one.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommitah/development/graphics-course/lecture10/transformation1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o -MF CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o.d -o CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o -c /home/tommitah/development/graphics-course/lecture10/transformation1/shader.cpp

CMakeFiles/lecture10_transformation_one.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lecture10_transformation_one.dir/shader.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tommitah/development/graphics-course/lecture10/transformation1/shader.cpp > CMakeFiles/lecture10_transformation_one.dir/shader.cpp.i

CMakeFiles/lecture10_transformation_one.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lecture10_transformation_one.dir/shader.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tommitah/development/graphics-course/lecture10/transformation1/shader.cpp -o CMakeFiles/lecture10_transformation_one.dir/shader.cpp.s

CMakeFiles/lecture10_transformation_one.dir/main.cpp.o: CMakeFiles/lecture10_transformation_one.dir/flags.make
CMakeFiles/lecture10_transformation_one.dir/main.cpp.o: /home/tommitah/development/graphics-course/lecture10/transformation1/main.cpp
CMakeFiles/lecture10_transformation_one.dir/main.cpp.o: CMakeFiles/lecture10_transformation_one.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommitah/development/graphics-course/lecture10/transformation1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lecture10_transformation_one.dir/main.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lecture10_transformation_one.dir/main.cpp.o -MF CMakeFiles/lecture10_transformation_one.dir/main.cpp.o.d -o CMakeFiles/lecture10_transformation_one.dir/main.cpp.o -c /home/tommitah/development/graphics-course/lecture10/transformation1/main.cpp

CMakeFiles/lecture10_transformation_one.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lecture10_transformation_one.dir/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tommitah/development/graphics-course/lecture10/transformation1/main.cpp > CMakeFiles/lecture10_transformation_one.dir/main.cpp.i

CMakeFiles/lecture10_transformation_one.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lecture10_transformation_one.dir/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tommitah/development/graphics-course/lecture10/transformation1/main.cpp -o CMakeFiles/lecture10_transformation_one.dir/main.cpp.s

# Object files for target lecture10_transformation_one
lecture10_transformation_one_OBJECTS = \
"CMakeFiles/lecture10_transformation_one.dir/glad.c.o" \
"CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o" \
"CMakeFiles/lecture10_transformation_one.dir/main.cpp.o"

# External object files for target lecture10_transformation_one
lecture10_transformation_one_EXTERNAL_OBJECTS =

lecture10_transformation_one: CMakeFiles/lecture10_transformation_one.dir/glad.c.o
lecture10_transformation_one: CMakeFiles/lecture10_transformation_one.dir/shader.cpp.o
lecture10_transformation_one: CMakeFiles/lecture10_transformation_one.dir/main.cpp.o
lecture10_transformation_one: CMakeFiles/lecture10_transformation_one.dir/build.make
lecture10_transformation_one: CMakeFiles/lecture10_transformation_one.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tommitah/development/graphics-course/lecture10/transformation1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lecture10_transformation_one"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lecture10_transformation_one.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lecture10_transformation_one.dir/build: lecture10_transformation_one
.PHONY : CMakeFiles/lecture10_transformation_one.dir/build

CMakeFiles/lecture10_transformation_one.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lecture10_transformation_one.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lecture10_transformation_one.dir/clean

CMakeFiles/lecture10_transformation_one.dir/depend:
	cd /home/tommitah/development/graphics-course/lecture10/transformation1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tommitah/development/graphics-course/lecture10/transformation1 /home/tommitah/development/graphics-course/lecture10/transformation1 /home/tommitah/development/graphics-course/lecture10/transformation1/build /home/tommitah/development/graphics-course/lecture10/transformation1/build /home/tommitah/development/graphics-course/lecture10/transformation1/build/CMakeFiles/lecture10_transformation_one.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lecture10_transformation_one.dir/depend

