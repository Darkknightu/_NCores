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
include CMakeFiles/Cores_DiskPerformanceTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cores_DiskPerformanceTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cores_DiskPerformanceTest.dir/flags.make

CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj: CMakeFiles/Cores_DiskPerformanceTest.dir/flags.make
CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj: CMakeFiles/Cores_DiskPerformanceTest.dir/includes_CXX.rsp
CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj: ../test/io/DiskPerformanceTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_DiskPerformanceTest.dir\test\io\DiskPerformanceTest.cpp.obj -c D:\Science\avro_c++\_NCores\test\io\DiskPerformanceTest.cpp

CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\test\io\DiskPerformanceTest.cpp > CMakeFiles\Cores_DiskPerformanceTest.dir\test\io\DiskPerformanceTest.cpp.i

CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\test\io\DiskPerformanceTest.cpp -o CMakeFiles\Cores_DiskPerformanceTest.dir\test\io\DiskPerformanceTest.cpp.s

# Object files for target Cores_DiskPerformanceTest
Cores_DiskPerformanceTest_OBJECTS = \
"CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj"

# External object files for target Cores_DiskPerformanceTest
Cores_DiskPerformanceTest_EXTERNAL_OBJECTS =

DiskPerformanceTest.exe: CMakeFiles/Cores_DiskPerformanceTest.dir/test/io/DiskPerformanceTest.cpp.obj
DiskPerformanceTest.exe: CMakeFiles/Cores_DiskPerformanceTest.dir/build.make
DiskPerformanceTest.exe: third-party/gtest-1.7.0/fused-src/gtest/libgtest.a
DiskPerformanceTest.exe: D:/MinGW/lib/libboost_program_options.a
DiskPerformanceTest.exe: D:/MinGW/lib/libboost_date_time.a
DiskPerformanceTest.exe: D:/MinGW/lib/libboost_filesystem.a
DiskPerformanceTest.exe: D:/MinGW/lib/libboost_iostreams.a
DiskPerformanceTest.exe: D:/MinGW/lib/libboost_regex.a
DiskPerformanceTest.exe: CMakeFiles/Cores_DiskPerformanceTest.dir/linklibs.rsp
DiskPerformanceTest.exe: CMakeFiles/Cores_DiskPerformanceTest.dir/objects1.rsp
DiskPerformanceTest.exe: CMakeFiles/Cores_DiskPerformanceTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DiskPerformanceTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cores_DiskPerformanceTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cores_DiskPerformanceTest.dir/build: DiskPerformanceTest.exe

.PHONY : CMakeFiles/Cores_DiskPerformanceTest.dir/build

CMakeFiles/Cores_DiskPerformanceTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cores_DiskPerformanceTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cores_DiskPerformanceTest.dir/clean

CMakeFiles/Cores_DiskPerformanceTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles\Cores_DiskPerformanceTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cores_DiskPerformanceTest.dir/depend
