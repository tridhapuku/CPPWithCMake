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
include CMakeFiles/AsSharedLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AsSharedLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AsSharedLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AsSharedLib.dir/flags.make

CMakeFiles/AsSharedLib.dir/main.cpp.obj: CMakeFiles/AsSharedLib.dir/flags.make
CMakeFiles/AsSharedLib.dir/main.cpp.obj: C:/Users/abhid/OneDrive\ -\ Arizona\ State\ University/Abhinav/Projects/TryCPP2/WithVSCode/main.cpp
CMakeFiles/AsSharedLib.dir/main.cpp.obj: CMakeFiles/AsSharedLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AsSharedLib.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AsSharedLib.dir/main.cpp.obj -MF CMakeFiles\AsSharedLib.dir\main.cpp.obj.d -o CMakeFiles\AsSharedLib.dir\main.cpp.obj -c "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\main.cpp"

CMakeFiles/AsSharedLib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AsSharedLib.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\main.cpp" > CMakeFiles\AsSharedLib.dir\main.cpp.i

CMakeFiles/AsSharedLib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AsSharedLib.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\main.cpp" -o CMakeFiles\AsSharedLib.dir\main.cpp.s

# Object files for target AsSharedLib
AsSharedLib_OBJECTS = \
"CMakeFiles/AsSharedLib.dir/main.cpp.obj"

# External object files for target AsSharedLib
AsSharedLib_EXTERNAL_OBJECTS =

bin/AsSharedLib.exe: CMakeFiles/AsSharedLib.dir/main.cpp.obj
bin/AsSharedLib.exe: CMakeFiles/AsSharedLib.dir/build.make
bin/AsSharedLib.exe: lib/libmath.dll.a
bin/AsSharedLib.exe: CMakeFiles/AsSharedLib.dir/linkLibs.rsp
bin/AsSharedLib.exe: CMakeFiles/AsSharedLib.dir/objects1
bin/AsSharedLib.exe: CMakeFiles/AsSharedLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\AsSharedLib.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AsSharedLib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AsSharedLib.dir/build: bin/AsSharedLib.exe
.PHONY : CMakeFiles/AsSharedLib.dir/build

CMakeFiles/AsSharedLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AsSharedLib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AsSharedLib.dir/clean

CMakeFiles/AsSharedLib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build" "C:\Users\abhid\OneDrive - Arizona State University\Abhinav\Projects\TryCPP2\WithVSCode\build\CMakeFiles\AsSharedLib.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AsSharedLib.dir/depend

