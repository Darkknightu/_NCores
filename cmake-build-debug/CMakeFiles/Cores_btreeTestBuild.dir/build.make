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
include CMakeFiles/Cores_btreeTestBuild.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cores_btreeTestBuild.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cores_btreeTestBuild.dir/flags.make

CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj: ../test/btree/btreeTestBuild.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\test\btree\btreeTestBuild.cpp.obj -c D:\Science\avro_c++\_NCores\test\btree\btreeTestBuild.cpp

CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\test\btree\btreeTestBuild.cpp > CMakeFiles\Cores_btreeTestBuild.dir\test\btree\btreeTestBuild.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\test\btree\btreeTestBuild.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\test\btree\btreeTestBuild.cpp.s

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj: ../src/btree/misc/global.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\misc\global.cpp.obj -c D:\Science\avro_c++\_NCores\src\btree\misc\global.cpp

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\src\btree\misc\global.cpp > CMakeFiles\Cores_btreeTestBuild.dir\src\btree\misc\global.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\src\btree\misc\global.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\misc\global.cpp.s

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj: ../src/btree/cache/cache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\cache\cache.cpp.obj -c D:\Science\avro_c++\_NCores\src\btree\cache\cache.cpp

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\src\btree\cache\cache.cpp > CMakeFiles\Cores_btreeTestBuild.dir\src\btree\cache\cache.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\src\btree\cache\cache.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\cache\cache.cpp.s

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj: ../src/btree/BTreeEntry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeEntry.cpp.obj -c D:\Science\avro_c++\_NCores\src\btree\BTreeEntry.cpp

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\src\btree\BTreeEntry.cpp > CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeEntry.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\src\btree\BTreeEntry.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeEntry.cpp.s

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj: ../src/btree/BTreeNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeNode.cpp.obj -c D:\Science\avro_c++\_NCores\src\btree\BTreeNode.cpp

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\src\btree\BTreeNode.cpp > CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeNode.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\src\btree\BTreeNode.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\BTreeNode.cpp.s

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/flags.make
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj: CMakeFiles/Cores_btreeTestBuild.dir/includes_CXX.rsp
CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj: ../src/btree/SerialBTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\SerialBTree.cpp.obj -c D:\Science\avro_c++\_NCores\src\btree\SerialBTree.cpp

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\src\btree\SerialBTree.cpp > CMakeFiles\Cores_btreeTestBuild.dir\src\btree\SerialBTree.cpp.i

CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\src\btree\SerialBTree.cpp -o CMakeFiles\Cores_btreeTestBuild.dir\src\btree\SerialBTree.cpp.s

# Object files for target Cores_btreeTestBuild
Cores_btreeTestBuild_OBJECTS = \
"CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj" \
"CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj" \
"CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj" \
"CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj" \
"CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj" \
"CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj"

# External object files for target Cores_btreeTestBuild
Cores_btreeTestBuild_EXTERNAL_OBJECTS =

btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/test/btree/btreeTestBuild.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/src/btree/misc/global.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/src/btree/cache/cache.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeEntry.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/src/btree/BTreeNode.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/src/btree/SerialBTree.cpp.obj
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/build.make
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/linklibs.rsp
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/objects1.rsp
btreeTestBuild.exe: CMakeFiles/Cores_btreeTestBuild.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable btreeTestBuild.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cores_btreeTestBuild.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cores_btreeTestBuild.dir/build: btreeTestBuild.exe

.PHONY : CMakeFiles/Cores_btreeTestBuild.dir/build

CMakeFiles/Cores_btreeTestBuild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cores_btreeTestBuild.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cores_btreeTestBuild.dir/clean

CMakeFiles/Cores_btreeTestBuild.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles\Cores_btreeTestBuild.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cores_btreeTestBuild.dir/depend

