# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /media/x/dados/jetbrains/Clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /media/x/dados/jetbrains/Clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth "

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/140_bandwidth_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/140_bandwidth_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/140_bandwidth_.dir/flags.make

CMakeFiles/140_bandwidth_.dir/main.cpp.o: CMakeFiles/140_bandwidth_.dir/flags.make
CMakeFiles/140_bandwidth_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/140_bandwidth_.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/140_bandwidth_.dir/main.cpp.o -c "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main.cpp"

CMakeFiles/140_bandwidth_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/140_bandwidth_.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main.cpp" > CMakeFiles/140_bandwidth_.dir/main.cpp.i

CMakeFiles/140_bandwidth_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/140_bandwidth_.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main.cpp" -o CMakeFiles/140_bandwidth_.dir/main.cpp.s

CMakeFiles/140_bandwidth_.dir/main2.cpp.o: CMakeFiles/140_bandwidth_.dir/flags.make
CMakeFiles/140_bandwidth_.dir/main2.cpp.o: ../main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/140_bandwidth_.dir/main2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/140_bandwidth_.dir/main2.cpp.o -c "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main2.cpp"

CMakeFiles/140_bandwidth_.dir/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/140_bandwidth_.dir/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main2.cpp" > CMakeFiles/140_bandwidth_.dir/main2.cpp.i

CMakeFiles/140_bandwidth_.dir/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/140_bandwidth_.dir/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /main2.cpp" -o CMakeFiles/140_bandwidth_.dir/main2.cpp.s

# Object files for target 140_bandwidth_
140_bandwidth__OBJECTS = \
"CMakeFiles/140_bandwidth_.dir/main.cpp.o" \
"CMakeFiles/140_bandwidth_.dir/main2.cpp.o"

# External object files for target 140_bandwidth_
140_bandwidth__EXTERNAL_OBJECTS =

140_bandwidth_: CMakeFiles/140_bandwidth_.dir/main.cpp.o
140_bandwidth_: CMakeFiles/140_bandwidth_.dir/main2.cpp.o
140_bandwidth_: CMakeFiles/140_bandwidth_.dir/build.make
140_bandwidth_: CMakeFiles/140_bandwidth_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 140_bandwidth_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/140_bandwidth_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/140_bandwidth_.dir/build: 140_bandwidth_

.PHONY : CMakeFiles/140_bandwidth_.dir/build

CMakeFiles/140_bandwidth_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/140_bandwidth_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/140_bandwidth_.dir/clean

CMakeFiles/140_bandwidth_.dir/depend:
	cd "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth " "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth " "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug" "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug" "/home/x/Área de Trabalho/TeP/TEP_tarefas/UVA/complete_search/iterative_fancy_techniques/140_bandwidth /cmake-build-debug/CMakeFiles/140_bandwidth_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/140_bandwidth_.dir/depend
