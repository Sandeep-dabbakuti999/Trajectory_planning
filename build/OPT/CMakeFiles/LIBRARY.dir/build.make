# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sandeep/Trajectory_planning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sandeep/Trajectory_planning/build

# Include any dependencies generated for this target.
include OPT/CMakeFiles/LIBRARY.dir/depend.make

# Include the progress variables for this target.
include OPT/CMakeFiles/LIBRARY.dir/progress.make

# Include the compile flags for this target's objects.
include OPT/CMakeFiles/LIBRARY.dir/flags.make

OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o: OPT/CMakeFiles/LIBRARY.dir/flags.make
OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o: ../OPT/Kinematicmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandeep/Trajectory_planning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o"
	cd /home/sandeep/Trajectory_planning/build/OPT && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o -c /home/sandeep/Trajectory_planning/OPT/Kinematicmodel.cpp

OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.i"
	cd /home/sandeep/Trajectory_planning/build/OPT && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sandeep/Trajectory_planning/OPT/Kinematicmodel.cpp > CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.i

OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.s"
	cd /home/sandeep/Trajectory_planning/build/OPT && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sandeep/Trajectory_planning/OPT/Kinematicmodel.cpp -o CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.s

# Object files for target LIBRARY
LIBRARY_OBJECTS = \
"CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o"

# External object files for target LIBRARY
LIBRARY_EXTERNAL_OBJECTS =

OPT/libLIBRARY.a: OPT/CMakeFiles/LIBRARY.dir/Kinematicmodel.cpp.o
OPT/libLIBRARY.a: OPT/CMakeFiles/LIBRARY.dir/build.make
OPT/libLIBRARY.a: OPT/CMakeFiles/LIBRARY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandeep/Trajectory_planning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLIBRARY.a"
	cd /home/sandeep/Trajectory_planning/build/OPT && $(CMAKE_COMMAND) -P CMakeFiles/LIBRARY.dir/cmake_clean_target.cmake
	cd /home/sandeep/Trajectory_planning/build/OPT && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LIBRARY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
OPT/CMakeFiles/LIBRARY.dir/build: OPT/libLIBRARY.a

.PHONY : OPT/CMakeFiles/LIBRARY.dir/build

OPT/CMakeFiles/LIBRARY.dir/clean:
	cd /home/sandeep/Trajectory_planning/build/OPT && $(CMAKE_COMMAND) -P CMakeFiles/LIBRARY.dir/cmake_clean.cmake
.PHONY : OPT/CMakeFiles/LIBRARY.dir/clean

OPT/CMakeFiles/LIBRARY.dir/depend:
	cd /home/sandeep/Trajectory_planning/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandeep/Trajectory_planning /home/sandeep/Trajectory_planning/OPT /home/sandeep/Trajectory_planning/build /home/sandeep/Trajectory_planning/build/OPT /home/sandeep/Trajectory_planning/build/OPT/CMakeFiles/LIBRARY.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OPT/CMakeFiles/LIBRARY.dir/depend
