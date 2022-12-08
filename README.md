# graphics course 2022

# deps
Running these programs requires binary packages that are packaged in the distro.
deps:
(Void) glfw, glfw-devel
(Ubuntu/other Debian) libglfw3 libglfw3-dev

# setup
unzip glad.zip
inside there's three files: glad.c, glad.h and khrplatform.h
the header files should go to /usr/include/glad
be sure to check that all three files have consistent #includes (clangd-lsp should catch these)

that leaves the glad.c file, which can be included in the source directory

# compiling and running
Compiling:
create a CMakeLists.txt file
mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make

To run:
./binary

# shaders
NOTE about shaders:
The LoadShaders function takes two paths: these are relative paths from
the build directory, not the file the function is ran from.
