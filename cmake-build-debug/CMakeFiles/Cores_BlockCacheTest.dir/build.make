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
include CMakeFiles/Cores_BlockCacheTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cores_BlockCacheTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cores_BlockCacheTest.dir/flags.make

CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj: CMakeFiles/Cores_BlockCacheTest.dir/flags.make
CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj: CMakeFiles/Cores_BlockCacheTest.dir/includes_CXX.rsp
CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj: ../test/block/buffer/BlockCacheTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_BlockCacheTest.dir\test\block\buffer\BlockCacheTest.cpp.obj -c D:\Science\avro_c++\_NCores\test\block\buffer\BlockCacheTest.cpp

CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\test\block\buffer\BlockCacheTest.cpp > CMakeFiles\Cores_BlockCacheTest.dir\test\block\buffer\BlockCacheTest.cpp.i

CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\test\block\buffer\BlockCacheTest.cpp -o CMakeFiles\Cores_BlockCacheTest.dir\test\block\buffer\BlockCacheTest.cpp.s

# Object files for target Cores_BlockCacheTest
Cores_BlockCacheTest_OBJECTS = \
"CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj"

# External object files for target Cores_BlockCacheTest
Cores_BlockCacheTest_EXTERNAL_OBJECTS =

BlockCacheTest.exe: CMakeFiles/Cores_BlockCacheTest.dir/test/block/buffer/BlockCacheTest.cpp.obj
BlockCacheTest.exe: CMakeFiles/Cores_BlockCacheTest.dir/build.make
BlockCacheTest.exe: third-party/gtest-1.7.0/fused-src/gtest/libgtest.a
BlockCacheTest.exe: D:/MinGW/lib/libboost_program_options.a
BlockCacheTest.exe: D:/MinGW/lib/libboost_date_time.a
BlockCacheTest.exe: D:/MinGW/lib/libboost_filesystem.a
BlockCacheTest.exe: D:/MinGW/lib/libboost_iostreams.a
BlockCacheTest.exe: D:/MinGW/lib/libboost_regex.a
BlockCacheTest.exe: CMakeFiles/Cores_BlockCacheTest.dir/linklibs.rsp
BlockCacheTest.exe: CMakeFiles/Cores_BlockCacheTest.dir/objects1.rsp
BlockCacheTest.exe: CMakeFiles/Cores_BlockCacheTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BlockCacheTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cores_BlockCacheTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cores_BlockCacheTest.dir/build: BlockCacheTest.exe

.PHONY : CMakeFiles/Cores_BlockCacheTest.dir/build

CMakeFiles/Cores_BlockCacheTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cores_BlockCacheTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cores_BlockCacheTest.dir/clean

CMakeFiles/Cores_BlockCacheTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles\Cores_BlockCacheTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cores_BlockCacheTest.dir/depend
