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
CMAKE_SOURCE_DIR = /mnt/c/Users/Joel/Dev/osmanip/sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Joel/Dev/osmanip/sandbox

# Include any dependencies generated for this target.
include CMakeFiles/osmanip_redirection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/osmanip_redirection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/osmanip_redirection.dir/flags.make

CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o: CMakeFiles/osmanip_redirection.dir/flags.make
CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o: src/redirection/output_redirector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Joel/Dev/osmanip/sandbox/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o -c /mnt/c/Users/Joel/Dev/osmanip/sandbox/src/redirection/output_redirector.cpp

CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Joel/Dev/osmanip/sandbox/src/redirection/output_redirector.cpp > CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.i

CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Joel/Dev/osmanip/sandbox/src/redirection/output_redirector.cpp -o CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.s

CMakeFiles/osmanip_redirection.dir/main.cpp.o: CMakeFiles/osmanip_redirection.dir/flags.make
CMakeFiles/osmanip_redirection.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Joel/Dev/osmanip/sandbox/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/osmanip_redirection.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/osmanip_redirection.dir/main.cpp.o -c /mnt/c/Users/Joel/Dev/osmanip/sandbox/main.cpp

CMakeFiles/osmanip_redirection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osmanip_redirection.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Joel/Dev/osmanip/sandbox/main.cpp > CMakeFiles/osmanip_redirection.dir/main.cpp.i

CMakeFiles/osmanip_redirection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osmanip_redirection.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Joel/Dev/osmanip/sandbox/main.cpp -o CMakeFiles/osmanip_redirection.dir/main.cpp.s

# Object files for target osmanip_redirection
osmanip_redirection_OBJECTS = \
"CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o" \
"CMakeFiles/osmanip_redirection.dir/main.cpp.o"

# External object files for target osmanip_redirection
osmanip_redirection_EXTERNAL_OBJECTS =

bin/osmanip_redirection: CMakeFiles/osmanip_redirection.dir/src/redirection/output_redirector.cpp.o
bin/osmanip_redirection: CMakeFiles/osmanip_redirection.dir/main.cpp.o
bin/osmanip_redirection: CMakeFiles/osmanip_redirection.dir/build.make
bin/osmanip_redirection: /mnt/c/Users/Joel/Dev/osmanip/lib/libosmanip.a
bin/osmanip_redirection: CMakeFiles/osmanip_redirection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Joel/Dev/osmanip/sandbox/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/osmanip_redirection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/osmanip_redirection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/osmanip_redirection.dir/build: bin/osmanip_redirection

.PHONY : CMakeFiles/osmanip_redirection.dir/build

CMakeFiles/osmanip_redirection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/osmanip_redirection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/osmanip_redirection.dir/clean

CMakeFiles/osmanip_redirection.dir/depend:
	cd /mnt/c/Users/Joel/Dev/osmanip/sandbox && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Joel/Dev/osmanip/sandbox /mnt/c/Users/Joel/Dev/osmanip/sandbox /mnt/c/Users/Joel/Dev/osmanip/sandbox /mnt/c/Users/Joel/Dev/osmanip/sandbox /mnt/c/Users/Joel/Dev/osmanip/sandbox/CMakeFiles/osmanip_redirection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/osmanip_redirection.dir/depend

