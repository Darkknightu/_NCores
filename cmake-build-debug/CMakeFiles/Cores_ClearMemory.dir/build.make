# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\cpp\CLion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\cpp\CLion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Science\avro_c++\_NCores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Science\avro_c++\_NCores\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cores_ClearMemory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cores_ClearMemory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cores_ClearMemory.dir/flags.make

CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj: CMakeFiles/Cores_ClearMemory.dir/flags.make
CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj: CMakeFiles/Cores_ClearMemory.dir/includes_CXX.rsp
CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj: ../test/utils/ClearMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_ClearMemory.dir\test\utils\ClearMemory.cpp.obj -c D:\Science\avro_c++\_NCores\test\utils\ClearMemory.cpp

CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\test\utils\ClearMemory.cpp > CMakeFiles\Cores_ClearMemory.dir\test\utils\ClearMemory.cpp.i

CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\test\utils\ClearMemory.cpp -o CMakeFiles\Cores_ClearMemory.dir\test\utils\ClearMemory.cpp.s

# Object files for target Cores_ClearMemory
Cores_ClearMemory_OBJECTS = \
"CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj"

# External object files for target Cores_ClearMemory
Cores_ClearMemory_EXTERNAL_OBJECTS =

ClearMemory.exe: CMakeFiles/Cores_ClearMemory.dir/test/utils/ClearMemory.cpp.obj
ClearMemory.exe: CMakeFiles/Cores_ClearMemory.dir/build.make
ClearMemory.exe: third-party/gtest-1.7.0/fused-src/gtest/libgtest.a
ClearMemory.exe: CMakeFiles/Cores_ClearMemory.dir/linklibs.rsp
ClearMemory.exe: CMakeFiles/Cores_ClearMemory.dir/objects1.rsp
ClearMemory.exe: CMakeFiles/Cores_ClearMemory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ClearMemory.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cores_ClearMemory.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cores_ClearMemory.dir/build: ClearMemory.exe

.PHONY : CMakeFiles/Cores_ClearMemory.dir/build

CMakeFiles/Cores_ClearMemory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cores_ClearMemory.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cores_ClearMemory.dir/clean

CMakeFiles/Cores_ClearMemory.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles\Cores_ClearMemory.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cores_ClearMemory.dir/depend

