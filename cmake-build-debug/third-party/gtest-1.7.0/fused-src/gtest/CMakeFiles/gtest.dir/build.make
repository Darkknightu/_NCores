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
include third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/flags.make

third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.obj: third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/flags.make
third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.obj: third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/includes_CXX.rsp
third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.obj: ../third-party/gtest-1.7.0/fused-src/gtest/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.obj"
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\gtest-all.cc.obj -c D:\Science\avro_c++\_NCores\third-party\gtest-1.7.0\fused-src\gtest\gtest-all.cc

third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/gtest-all.cc.i"
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Science\avro_c++\_NCores\third-party\gtest-1.7.0\fused-src\gtest\gtest-all.cc > CMakeFiles\gtest.dir\gtest-all.cc.i

third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/gtest-all.cc.s"
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Science\avro_c++\_NCores\third-party\gtest-1.7.0\fused-src\gtest\gtest-all.cc -o CMakeFiles\gtest.dir\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

third-party/gtest-1.7.0/fused-src/gtest/libgtest.a: third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/gtest-all.cc.obj
third-party/gtest-1.7.0/fused-src/gtest/libgtest.a: third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/build.make
third-party/gtest-1.7.0/fused-src/gtest/libgtest.a: third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Science\avro_c++\_NCores\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/build: third-party/gtest-1.7.0/fused-src/gtest/libgtest.a

.PHONY : third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/build

third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/clean:
	cd /d D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/clean

third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Science\avro_c++\_NCores D:\Science\avro_c++\_NCores\third-party\gtest-1.7.0\fused-src\gtest D:\Science\avro_c++\_NCores\cmake-build-debug D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest D:\Science\avro_c++\_NCores\cmake-build-debug\third-party\gtest-1.7.0\fused-src\gtest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/gtest-1.7.0/fused-src/gtest/CMakeFiles/gtest.dir/depend
