# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "J:\Program\C\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "J:\Program\C\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bogda\cursach2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bogda\cursach2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cursach2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cursach2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cursach2.dir/flags.make

CMakeFiles/cursach2.dir/main.c.obj: CMakeFiles/cursach2.dir/flags.make
CMakeFiles/cursach2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\bogda\cursach2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cursach2.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cursach2.dir\main.c.obj   -c C:\Users\bogda\cursach2\main.c

CMakeFiles/cursach2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursach2.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\bogda\cursach2\main.c > CMakeFiles\cursach2.dir\main.c.i

CMakeFiles/cursach2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursach2.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\bogda\cursach2\main.c -o CMakeFiles\cursach2.dir\main.c.s

# Object files for target cursach2
cursach2_OBJECTS = \
"CMakeFiles/cursach2.dir/main.c.obj"

# External object files for target cursach2
cursach2_EXTERNAL_OBJECTS =

cursach2.exe: CMakeFiles/cursach2.dir/main.c.obj
cursach2.exe: CMakeFiles/cursach2.dir/build.make
cursach2.exe: CMakeFiles/cursach2.dir/linklibs.rsp
cursach2.exe: CMakeFiles/cursach2.dir/objects1.rsp
cursach2.exe: CMakeFiles/cursach2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\bogda\cursach2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cursach2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cursach2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cursach2.dir/build: cursach2.exe

.PHONY : CMakeFiles/cursach2.dir/build

CMakeFiles/cursach2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cursach2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cursach2.dir/clean

CMakeFiles/cursach2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\bogda\cursach2 C:\Users\bogda\cursach2 C:\Users\bogda\cursach2\cmake-build-debug C:\Users\bogda\cursach2\cmake-build-debug C:\Users\bogda\cursach2\cmake-build-debug\CMakeFiles\cursach2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cursach2.dir/depend

