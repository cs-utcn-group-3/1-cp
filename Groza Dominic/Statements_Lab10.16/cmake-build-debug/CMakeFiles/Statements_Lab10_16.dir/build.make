# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Statements_Lab10_16.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Statements_Lab10_16.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Statements_Lab10_16.dir/flags.make

CMakeFiles/Statements_Lab10_16.dir/main.c.obj: CMakeFiles/Statements_Lab10_16.dir/flags.make
CMakeFiles/Statements_Lab10_16.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Statements_Lab10_16.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Statements_Lab10_16.dir\main.c.obj   -c "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\main.c"

CMakeFiles/Statements_Lab10_16.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Statements_Lab10_16.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\main.c" > CMakeFiles\Statements_Lab10_16.dir\main.c.i

CMakeFiles/Statements_Lab10_16.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Statements_Lab10_16.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\main.c" -o CMakeFiles\Statements_Lab10_16.dir\main.c.s

# Object files for target Statements_Lab10_16
Statements_Lab10_16_OBJECTS = \
"CMakeFiles/Statements_Lab10_16.dir/main.c.obj"

# External object files for target Statements_Lab10_16
Statements_Lab10_16_EXTERNAL_OBJECTS =

Statements_Lab10_16.exe: CMakeFiles/Statements_Lab10_16.dir/main.c.obj
Statements_Lab10_16.exe: CMakeFiles/Statements_Lab10_16.dir/build.make
Statements_Lab10_16.exe: CMakeFiles/Statements_Lab10_16.dir/linklibs.rsp
Statements_Lab10_16.exe: CMakeFiles/Statements_Lab10_16.dir/objects1.rsp
Statements_Lab10_16.exe: CMakeFiles/Statements_Lab10_16.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Statements_Lab10_16.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Statements_Lab10_16.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Statements_Lab10_16.dir/build: Statements_Lab10_16.exe

.PHONY : CMakeFiles/Statements_Lab10_16.dir/build

CMakeFiles/Statements_Lab10_16.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Statements_Lab10_16.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Statements_Lab10_16.dir/clean

CMakeFiles/Statements_Lab10_16.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16" "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16" "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug" "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug" "C:\Users\Dominic\Desktop\Stuff\CP\CP Lab\Git\1-cp\Groza Dominic\Statements_Lab10.16\cmake-build-debug\CMakeFiles\Statements_Lab10_16.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Statements_Lab10_16.dir/depend
