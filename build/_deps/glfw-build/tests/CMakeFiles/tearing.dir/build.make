# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yura\Desktop\glfw_imgui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yura\Desktop\glfw_imgui\build

# Include any dependencies generated for this target.
include _deps/glfw-build/tests/CMakeFiles/tearing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/glfw-build/tests/CMakeFiles/tearing.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/glfw-build/tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/glfw-build/tests/CMakeFiles/tearing.dir/flags.make

_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/flags.make
_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/includes_C.rsp
_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj: _deps/glfw-src/tests/tearing.c
_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yura\Desktop\glfw_imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj -MF CMakeFiles\tearing.dir\tearing.c.obj.d -o CMakeFiles\tearing.dir\tearing.c.obj -c C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\tests\tearing.c

_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\tests\tearing.c > CMakeFiles\tearing.dir\tearing.c.i

_deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\tests\tearing.c -o CMakeFiles\tearing.dir\tearing.c.s

_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/flags.make
_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/includes_C.rsp
_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: _deps/glfw-src/deps/glad_gl.c
_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: _deps/glfw-build/tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yura\Desktop\glfw_imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object _deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\tearing.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\tearing.dir\__\deps\glad_gl.c.obj -c C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\deps\glad_gl.c

_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\deps\glad_gl.c > CMakeFiles\tearing.dir\__\deps\glad_gl.c.i

_deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && C:\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\deps\glad_gl.c -o CMakeFiles\tearing.dir\__\deps\glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.obj" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/tearing.c.obj
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/build.make
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/src/libglfw3.a
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/linkLibs.rsp
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/objects1
_deps/glfw-build/tests/tearing.exe: _deps/glfw-build/tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yura\Desktop\glfw_imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tearing.exe"
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tearing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/glfw-build/tests/CMakeFiles/tearing.dir/build: _deps/glfw-build/tests/tearing.exe
.PHONY : _deps/glfw-build/tests/CMakeFiles/tearing.dir/build

_deps/glfw-build/tests/CMakeFiles/tearing.dir/clean:
	cd /d C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests && $(CMAKE_COMMAND) -P CMakeFiles\tearing.dir\cmake_clean.cmake
.PHONY : _deps/glfw-build/tests/CMakeFiles/tearing.dir/clean

_deps/glfw-build/tests/CMakeFiles/tearing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yura\Desktop\glfw_imgui C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-src\tests C:\Users\yura\Desktop\glfw_imgui\build C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests C:\Users\yura\Desktop\glfw_imgui\build\_deps\glfw-build\tests\CMakeFiles\tearing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/glfw-build/tests/CMakeFiles/tearing.dir/depend

