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
CMAKE_SOURCE_DIR = /home/marwan/cs166/weakly-queueish-structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marwan/cs166/weakly-queueish-structures/build-dir

# Include any dependencies generated for this target.
include CMakeFiles/weakly_queueish_structures.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/weakly_queueish_structures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/weakly_queueish_structures.dir/flags.make

CMakeFiles/weakly_queueish_structures.dir/main.cpp.o: CMakeFiles/weakly_queueish_structures.dir/flags.make
CMakeFiles/weakly_queueish_structures.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/weakly_queueish_structures.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakly_queueish_structures.dir/main.cpp.o -c /home/marwan/cs166/weakly-queueish-structures/main.cpp

CMakeFiles/weakly_queueish_structures.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakly_queueish_structures.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/cs166/weakly-queueish-structures/main.cpp > CMakeFiles/weakly_queueish_structures.dir/main.cpp.i

CMakeFiles/weakly_queueish_structures.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakly_queueish_structures.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/cs166/weakly-queueish-structures/main.cpp -o CMakeFiles/weakly_queueish_structures.dir/main.cpp.s

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o: CMakeFiles/weakly_queueish_structures.dir/flags.make
CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o: ../generics_attempt/WeaklyQueueishSearch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o -c /home/marwan/cs166/weakly-queueish-structures/generics_attempt/WeaklyQueueishSearch.cpp

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/cs166/weakly-queueish-structures/generics_attempt/WeaklyQueueishSearch.cpp > CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.i

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/cs166/weakly-queueish-structures/generics_attempt/WeaklyQueueishSearch.cpp -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.s

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o: CMakeFiles/weakly_queueish_structures.dir/flags.make
CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o: ../generics_attempt/SearchStructure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o -c /home/marwan/cs166/weakly-queueish-structures/generics_attempt/SearchStructure.cpp

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/cs166/weakly-queueish-structures/generics_attempt/SearchStructure.cpp > CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.i

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/cs166/weakly-queueish-structures/generics_attempt/SearchStructure.cpp -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.s

CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o: CMakeFiles/weakly_queueish_structures.dir/flags.make
CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o: ../Dict.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o -c /home/marwan/cs166/weakly-queueish-structures/Dict.cpp

CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/cs166/weakly-queueish-structures/Dict.cpp > CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.i

CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/cs166/weakly-queueish-structures/Dict.cpp -o CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.s

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o: CMakeFiles/weakly_queueish_structures.dir/flags.make
CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o: ../generics_attempt/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o -c /home/marwan/cs166/weakly-queueish-structures/generics_attempt/Test.cpp

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/cs166/weakly-queueish-structures/generics_attempt/Test.cpp > CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.i

CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/cs166/weakly-queueish-structures/generics_attempt/Test.cpp -o CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.s

# Object files for target weakly_queueish_structures
weakly_queueish_structures_OBJECTS = \
"CMakeFiles/weakly_queueish_structures.dir/main.cpp.o" \
"CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o" \
"CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o" \
"CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o" \
"CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o"

# External object files for target weakly_queueish_structures
weakly_queueish_structures_EXTERNAL_OBJECTS =

weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/main.cpp.o
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/generics_attempt/WeaklyQueueishSearch.cpp.o
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/generics_attempt/SearchStructure.cpp.o
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/Dict.cpp.o
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/generics_attempt/Test.cpp.o
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/build.make
weakly_queueish_structures: CMakeFiles/weakly_queueish_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable weakly_queueish_structures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/weakly_queueish_structures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/weakly_queueish_structures.dir/build: weakly_queueish_structures

.PHONY : CMakeFiles/weakly_queueish_structures.dir/build

CMakeFiles/weakly_queueish_structures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/weakly_queueish_structures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/weakly_queueish_structures.dir/clean

CMakeFiles/weakly_queueish_structures.dir/depend:
	cd /home/marwan/cs166/weakly-queueish-structures/build-dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marwan/cs166/weakly-queueish-structures /home/marwan/cs166/weakly-queueish-structures /home/marwan/cs166/weakly-queueish-structures/build-dir /home/marwan/cs166/weakly-queueish-structures/build-dir /home/marwan/cs166/weakly-queueish-structures/build-dir/CMakeFiles/weakly_queueish_structures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/weakly_queueish_structures.dir/depend

