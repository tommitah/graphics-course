# graphics course 2022

# deps
Running these programs requires binary packages that are packaged in the distro.
In addition to this, the code uses glad (redhat) instead of glew for extensions.
Glad is included in the repo.
deps:

(Void) ```sudo xbps-install -S glfw glfw-devel glm```

(Ubuntu/other Debian) ```sudo apt install libglfw3 libglfw3-dev libglm libglm-dev```

# setup
Clone this repo with ```git clone <url>```.

```unzip glad.zip```.

Inside there's three files: ```glad.c```, ```glad.h``` and ```khrplatform.h```.
The header files should go to /usr/include/glad.

Be sure to check that all three files have consistent #includes (clangd-lsp should catch these).

That leaves the glad.c file, which can be included in the source directory.

# compiling and running
if present, remove the ```build/```, ```.cache/``` and ```compile_commands.json``` directories
and files.

```rm -rf build/ .cache/ compile_commands.json```

Compiling:

create a CMakeLists.txt file
```
mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
ln -s compile_commands.json ..
make
```
To run:
```
./binary
```
# shaders
NOTE about shaders:
The LoadShaders function takes two paths: these are relative paths from
the build directory, not the file the function is ran from.
