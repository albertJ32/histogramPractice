# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build"

# Include any dependencies generated for this target.
include CMakeFiles/HistCalc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HistCalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HistCalc.dir/flags.make

CMakeFiles/HistCalc.dir/HistCalc.cpp.o: CMakeFiles/HistCalc.dir/flags.make
CMakeFiles/HistCalc.dir/HistCalc.cpp.o: ../HistCalc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HistCalc.dir/HistCalc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HistCalc.dir/HistCalc.cpp.o -c "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/HistCalc.cpp"

CMakeFiles/HistCalc.dir/HistCalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HistCalc.dir/HistCalc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/HistCalc.cpp" > CMakeFiles/HistCalc.dir/HistCalc.cpp.i

CMakeFiles/HistCalc.dir/HistCalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HistCalc.dir/HistCalc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/HistCalc.cpp" -o CMakeFiles/HistCalc.dir/HistCalc.cpp.s

CMakeFiles/HistCalc.dir/HistCalc.cpp.o.requires:
.PHONY : CMakeFiles/HistCalc.dir/HistCalc.cpp.o.requires

CMakeFiles/HistCalc.dir/HistCalc.cpp.o.provides: CMakeFiles/HistCalc.dir/HistCalc.cpp.o.requires
	$(MAKE) -f CMakeFiles/HistCalc.dir/build.make CMakeFiles/HistCalc.dir/HistCalc.cpp.o.provides.build
.PHONY : CMakeFiles/HistCalc.dir/HistCalc.cpp.o.provides

CMakeFiles/HistCalc.dir/HistCalc.cpp.o.provides.build: CMakeFiles/HistCalc.dir/HistCalc.cpp.o

# Object files for target HistCalc
HistCalc_OBJECTS = \
"CMakeFiles/HistCalc.dir/HistCalc.cpp.o"

# External object files for target HistCalc
HistCalc_EXTERNAL_OBJECTS =

HistCalc: CMakeFiles/HistCalc.dir/HistCalc.cpp.o
HistCalc: CMakeFiles/HistCalc.dir/build.make
HistCalc: /usr/local/lib/libopencv_videostab.so.3.0.0
HistCalc: /usr/local/lib/libopencv_videoio.so.3.0.0
HistCalc: /usr/local/lib/libopencv_video.so.3.0.0
HistCalc: /usr/local/lib/libopencv_ts.a
HistCalc: /usr/local/lib/libopencv_superres.so.3.0.0
HistCalc: /usr/local/lib/libopencv_stitching.so.3.0.0
HistCalc: /usr/local/lib/libopencv_shape.so.3.0.0
HistCalc: /usr/local/lib/libopencv_photo.so.3.0.0
HistCalc: /usr/local/lib/libopencv_objdetect.so.3.0.0
HistCalc: /usr/local/lib/libopencv_ml.so.3.0.0
HistCalc: /usr/local/lib/libopencv_imgproc.so.3.0.0
HistCalc: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
HistCalc: /usr/local/lib/libopencv_highgui.so.3.0.0
HistCalc: /usr/local/lib/libopencv_hal.a
HistCalc: /usr/local/lib/libopencv_flann.so.3.0.0
HistCalc: /usr/local/lib/libopencv_features2d.so.3.0.0
HistCalc: /usr/local/lib/libopencv_core.so.3.0.0
HistCalc: /usr/local/lib/libopencv_calib3d.so.3.0.0
HistCalc: /usr/local/lib/libopencv_features2d.so.3.0.0
HistCalc: /usr/local/lib/libopencv_ml.so.3.0.0
HistCalc: /usr/local/lib/libopencv_highgui.so.3.0.0
HistCalc: /usr/local/lib/libopencv_videoio.so.3.0.0
HistCalc: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
HistCalc: /usr/local/lib/libopencv_flann.so.3.0.0
HistCalc: /usr/local/lib/libopencv_video.so.3.0.0
HistCalc: /usr/local/lib/libopencv_imgproc.so.3.0.0
HistCalc: /usr/local/lib/libopencv_core.so.3.0.0
HistCalc: /usr/local/lib/libopencv_hal.a
HistCalc: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
HistCalc: CMakeFiles/HistCalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable HistCalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HistCalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HistCalc.dir/build: HistCalc
.PHONY : CMakeFiles/HistCalc.dir/build

CMakeFiles/HistCalc.dir/requires: CMakeFiles/HistCalc.dir/HistCalc.cpp.o.requires
.PHONY : CMakeFiles/HistCalc.dir/requires

CMakeFiles/HistCalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HistCalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HistCalc.dir/clean

CMakeFiles/HistCalc.dir/depend:
	cd "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc" "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc" "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build" "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build" "/home/james-tt/Dropbox/Term 2/Final project/OpenCv Programs/3 Image Processing/HistCalc/build/CMakeFiles/HistCalc.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/HistCalc.dir/depend

