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
CMAKE_SOURCE_DIR = "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build"

# Include any dependencies generated for this target.
include CMakeFiles/math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/math.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/math.dir/flags.make

CMakeFiles/math.dir/lib/math/operations.cpp.obj: CMakeFiles/math.dir/flags.make
CMakeFiles/math.dir/lib/math/operations.cpp.obj: C:/Users/abhid/OneDrive\ -\ Arizona\ State\ University/Abhinav/Projects/TryCPP2/WithVSCode/lib/math/operations.cpp
CMakeFiles/math.dir/lib/math/operations.cpp.obj: CMakeFiles/math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/math.dir/lib/math/operations.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/math.dir/lib/math/operations.cpp.obj -MF CMakeFiles\math.dir\lib\math\operations.cpp.obj.d -o CMakeFiles\math.dir\lib\math\operations.cpp.obj -c "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\lib\math\operations.cpp"

CMakeFiles/math.dir/lib/math/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/lib/math/operations.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\lib\math\operations.cpp" > CMakeFiles\math.dir\lib\math\operations.cpp.i

CMakeFiles/math.dir/lib/math/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/lib/math/operations.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\lib\math\operations.cpp" -o CMakeFiles\math.dir\lib\math\operations.cpp.s

# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/lib/math/operations.cpp.obj"

# External object files for target math
math_EXTERNAL_OBJECTS =

libmath.a: CMakeFiles/math.dir/lib/math/operations.cpp.obj
libmath.a: CMakeFiles/math.dir/build.make
libmath.a: CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmath.a"
	$(CMAKE_COMMAND) -P CMakeFiles\math.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\math.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/math.dir/build: libmath.a
.PHONY : CMakeFiles/math.dir/build

CMakeFiles/math.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\math.dir\cmake_clean.cmake
.PHONY : CMakeFiles/math.dir/clean

CMakeFiles/math.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles\math.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/math.dir/depend

