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
CMAKE_SOURCE_DIR = /home/tommitah/development/graphics-course/lecture9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tommitah/development/graphics-course/lecture9/build

# Include any dependencies generated for this target.
include CMakeFiles/babbys_first_triangle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/babbys_first_triangle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/babbys_first_triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/babbys_first_triangle.dir/flags.make

CMakeFiles/babbys_first_triangle.dir/glad.c.o: CMakeFiles/babbys_first_triangle.dir/flags.make
CMakeFiles/babbys_first_triangle.dir/glad.c.o: /home/tommitah/development/graphics-course/lecture9/glad.c
CMakeFiles/babbys_first_triangle.dir/glad.c.o: CMakeFiles/babbys_first_triangle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommitah/development/graphics-course/lecture9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/babbys_first_triangle.dir/glad.c.o"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/babbys_first_triangle.dir/glad.c.o -MF CMakeFiles/babbys_first_triangle.dir/glad.c.o.d -o CMakeFiles/babbys_first_triangle.dir/glad.c.o -c /home/tommitah/development/graphics-course/lecture9/glad.c

CMakeFiles/babbys_first_triangle.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/babbys_first_triangle.dir/glad.c.i"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tommitah/development/graphics-course/lecture9/glad.c > CMakeFiles/babbys_first_triangle.dir/glad.c.i

CMakeFiles/babbys_first_triangle.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/babbys_first_triangle.dir/glad.c.s"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tommitah/development/graphics-course/lecture9/glad.c -o CMakeFiles/babbys_first_triangle.dir/glad.c.s

CMakeFiles/babbys_first_triangle.dir/main.cpp.o: CMakeFiles/babbys_first_triangle.dir/flags.make
CMakeFiles/babbys_first_triangle.dir/main.cpp.o: /home/tommitah/development/graphics-course/lecture9/main.cpp
CMakeFiles/babbys_first_triangle.dir/main.cpp.o: CMakeFiles/babbys_first_triangle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommitah/development/graphics-course/lecture9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/babbys_first_triangle.dir/main.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/babbys_first_triangle.dir/main.cpp.o -MF CMakeFiles/babbys_first_triangle.dir/main.cpp.o.d -o CMakeFiles/babbys_first_triangle.dir/main.cpp.o -c /home/tommitah/development/graphics-course/lecture9/main.cpp

CMakeFiles/babbys_first_triangle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babbys_first_triangle.dir/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tommitah/development/graphics-course/lecture9/main.cpp > CMakeFiles/babbys_first_triangle.dir/main.cpp.i

CMakeFiles/babbys_first_triangle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babbys_first_triangle.dir/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tommitah/development/graphics-course/lecture9/main.cpp -o CMakeFiles/babbys_first_triangle.dir/main.cpp.s

# Object files for target babbys_first_triangle
babbys_first_triangle_OBJECTS = \
"CMakeFiles/babbys_first_triangle.dir/glad.c.o" \
"CMakeFiles/babbys_first_triangle.dir/main.cpp.o"

# External object files for target babbys_first_triangle
babbys_first_triangle_EXTERNAL_OBJECTS =

babbys_first_triangle: CMakeFiles/babbys_first_triangle.dir/glad.c.o
babbys_first_triangle: CMakeFiles/babbys_first_triangle.dir/main.cpp.o
babbys_first_triangle: CMakeFiles/babbys_first_triangle.dir/build.make
babbys_first_triangle: CMakeFiles/babbys_first_triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tommitah/development/graphics-course/lecture9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable babbys_first_triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/babbys_first_triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/babbys_first_triangle.dir/build: babbys_first_triangle
.PHONY : CMakeFiles/babbys_first_triangle.dir/build

CMakeFiles/babbys_first_triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/babbys_first_triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/babbys_first_triangle.dir/clean

CMakeFiles/babbys_first_triangle.dir/depend:
	cd /home/tommitah/development/graphics-course/lecture9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tommitah/development/graphics-course/lecture9 /home/tommitah/development/graphics-course/lecture9 /home/tommitah/development/graphics-course/lecture9/build /home/tommitah/development/graphics-course/lecture9/build /home/tommitah/development/graphics-course/lecture9/build/CMakeFiles/babbys_first_triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/babbys_first_triangle.dir/depend

