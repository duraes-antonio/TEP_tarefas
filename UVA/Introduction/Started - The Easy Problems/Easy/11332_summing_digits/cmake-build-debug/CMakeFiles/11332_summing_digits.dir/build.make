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
CMAKE_SOURCE_DIR = "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/11332_summing_digits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/11332_summing_digits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11332_summing_digits.dir/flags.make

CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o: CMakeFiles/11332_summing_digits.dir/flags.make
CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o: ../11332_summing_digits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o -c "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/11332_summing_digits.cpp"

CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/11332_summing_digits.cpp" > CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.i

CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/11332_summing_digits.cpp" -o CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.s

# Object files for target 11332_summing_digits
11332_summing_digits_OBJECTS = \
"CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o"

# External object files for target 11332_summing_digits
11332_summing_digits_EXTERNAL_OBJECTS =

11332_summing_digits: CMakeFiles/11332_summing_digits.dir/11332_summing_digits.cpp.o
11332_summing_digits: CMakeFiles/11332_summing_digits.dir/build.make
11332_summing_digits: CMakeFiles/11332_summing_digits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11332_summing_digits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11332_summing_digits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11332_summing_digits.dir/build: 11332_summing_digits

.PHONY : CMakeFiles/11332_summing_digits.dir/build

CMakeFiles/11332_summing_digits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11332_summing_digits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11332_summing_digits.dir/clean

CMakeFiles/11332_summing_digits.dir/depend:
	cd "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits" "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits" "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug" "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug" "/home/x/Área de Trabalho/TeP/UVA/Introduction/Started - The Easy Problems/Easy/11332_summing_digits/cmake-build-debug/CMakeFiles/11332_summing_digits.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/11332_summing_digits.dir/depend

