# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/petrsejvl/Dropbox/pa2/server2/pa2_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pa2_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa2_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa2_server.dir/flags.make

CMakeFiles/pa2_server.dir/src/main.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa2_server.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/main.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/main.cpp

CMakeFiles/pa2_server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/main.cpp > CMakeFiles/pa2_server.dir/src/main.cpp.i

CMakeFiles/pa2_server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/main.cpp -o CMakeFiles/pa2_server.dir/src/main.cpp.s

CMakeFiles/pa2_server.dir/src/server.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/server.cpp.o: ../src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa2_server.dir/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/server.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/server.cpp

CMakeFiles/pa2_server.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/server.cpp > CMakeFiles/pa2_server.dir/src/server.cpp.i

CMakeFiles/pa2_server.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/server.cpp -o CMakeFiles/pa2_server.dir/src/server.cpp.s

CMakeFiles/pa2_server.dir/src/worker.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/worker.cpp.o: ../src/worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa2_server.dir/src/worker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/worker.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/worker.cpp

CMakeFiles/pa2_server.dir/src/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/worker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/worker.cpp > CMakeFiles/pa2_server.dir/src/worker.cpp.i

CMakeFiles/pa2_server.dir/src/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/worker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/worker.cpp -o CMakeFiles/pa2_server.dir/src/worker.cpp.s

CMakeFiles/pa2_server.dir/src/logger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logger.cpp.o: ../src/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa2_server.dir/src/logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger.cpp

CMakeFiles/pa2_server.dir/src/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger.cpp > CMakeFiles/pa2_server.dir/src/logger.cpp.i

CMakeFiles/pa2_server.dir/src/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger.cpp -o CMakeFiles/pa2_server.dir/src/logger.cpp.s

CMakeFiles/pa2_server.dir/src/log.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log.cpp.o: ../src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pa2_server.dir/src/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log.cpp

CMakeFiles/pa2_server.dir/src/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log.cpp > CMakeFiles/pa2_server.dir/src/log.cpp.i

CMakeFiles/pa2_server.dir/src/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log.cpp -o CMakeFiles/pa2_server.dir/src/log.cpp.s

CMakeFiles/pa2_server.dir/src/controller.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pa2_server.dir/src/controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/controller.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/controller.cpp

CMakeFiles/pa2_server.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/controller.cpp > CMakeFiles/pa2_server.dir/src/controller.cpp.i

CMakeFiles/pa2_server.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/controller.cpp -o CMakeFiles/pa2_server.dir/src/controller.cpp.s

CMakeFiles/pa2_server.dir/src/parser.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/parser.cpp.o: ../src/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pa2_server.dir/src/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/parser.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/parser.cpp

CMakeFiles/pa2_server.dir/src/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/parser.cpp > CMakeFiles/pa2_server.dir/src/parser.cpp.i

CMakeFiles/pa2_server.dir/src/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/parser.cpp -o CMakeFiles/pa2_server.dir/src/parser.cpp.s

CMakeFiles/pa2_server.dir/src/request.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/request.cpp.o: ../src/request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pa2_server.dir/src/request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/request.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/request.cpp

CMakeFiles/pa2_server.dir/src/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/request.cpp > CMakeFiles/pa2_server.dir/src/request.cpp.i

CMakeFiles/pa2_server.dir/src/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/request.cpp -o CMakeFiles/pa2_server.dir/src/request.cpp.s

CMakeFiles/pa2_server.dir/src/response.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/response.cpp.o: ../src/response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pa2_server.dir/src/response.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/response.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/response.cpp

CMakeFiles/pa2_server.dir/src/response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/response.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/response.cpp > CMakeFiles/pa2_server.dir/src/response.cpp.i

CMakeFiles/pa2_server.dir/src/response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/response.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/response.cpp -o CMakeFiles/pa2_server.dir/src/response.cpp.s

CMakeFiles/pa2_server.dir/src/responseLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/responseLog.cpp.o: ../src/responseLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pa2_server.dir/src/responseLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/responseLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/responseLog.cpp

CMakeFiles/pa2_server.dir/src/responseLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/responseLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/responseLog.cpp > CMakeFiles/pa2_server.dir/src/responseLog.cpp.i

CMakeFiles/pa2_server.dir/src/responseLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/responseLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/responseLog.cpp -o CMakeFiles/pa2_server.dir/src/responseLog.cpp.s

CMakeFiles/pa2_server.dir/src/requestLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/requestLog.cpp.o: ../src/requestLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pa2_server.dir/src/requestLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/requestLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/requestLog.cpp

CMakeFiles/pa2_server.dir/src/requestLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/requestLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/requestLog.cpp > CMakeFiles/pa2_server.dir/src/requestLog.cpp.i

CMakeFiles/pa2_server.dir/src/requestLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/requestLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/requestLog.cpp -o CMakeFiles/pa2_server.dir/src/requestLog.cpp.s

CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o: ../src/shutdownLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/shutdownLog.cpp

CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/shutdownLog.cpp > CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.i

CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/shutdownLog.cpp -o CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.s

CMakeFiles/pa2_server.dir/src/errorLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/errorLog.cpp.o: ../src/errorLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pa2_server.dir/src/errorLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/errorLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/errorLog.cpp

CMakeFiles/pa2_server.dir/src/errorLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/errorLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/errorLog.cpp > CMakeFiles/pa2_server.dir/src/errorLog.cpp.i

CMakeFiles/pa2_server.dir/src/errorLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/errorLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/errorLog.cpp -o CMakeFiles/pa2_server.dir/src/errorLog.cpp.s

CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o: ../src/consoleLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/consoleLogger.cpp

CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/consoleLogger.cpp > CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.i

CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/consoleLogger.cpp -o CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.s

CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o: ../src/fileLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileLogger.cpp

CMakeFiles/pa2_server.dir/src/fileLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/fileLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileLogger.cpp > CMakeFiles/pa2_server.dir/src/fileLogger.cpp.i

CMakeFiles/pa2_server.dir/src/fileLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/fileLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileLogger.cpp -o CMakeFiles/pa2_server.dir/src/fileLogger.cpp.s

CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o: ../src/fileResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileResponse.cpp

CMakeFiles/pa2_server.dir/src/fileResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/fileResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileResponse.cpp > CMakeFiles/pa2_server.dir/src/fileResponse.cpp.i

CMakeFiles/pa2_server.dir/src/fileResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/fileResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/fileResponse.cpp -o CMakeFiles/pa2_server.dir/src/fileResponse.cpp.s

CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o: ../src/dirResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/dirResponse.cpp

CMakeFiles/pa2_server.dir/src/dirResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/dirResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/dirResponse.cpp > CMakeFiles/pa2_server.dir/src/dirResponse.cpp.i

CMakeFiles/pa2_server.dir/src/dirResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/dirResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/dirResponse.cpp -o CMakeFiles/pa2_server.dir/src/dirResponse.cpp.s

CMakeFiles/pa2_server.dir/src/execResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/execResponse.cpp.o: ../src/execResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/pa2_server.dir/src/execResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/execResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/execResponse.cpp

CMakeFiles/pa2_server.dir/src/execResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/execResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/execResponse.cpp > CMakeFiles/pa2_server.dir/src/execResponse.cpp.i

CMakeFiles/pa2_server.dir/src/execResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/execResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/execResponse.cpp -o CMakeFiles/pa2_server.dir/src/execResponse.cpp.s

CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o: ../src/notFoundResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/notFoundResponse.cpp

CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/notFoundResponse.cpp > CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.i

CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/notFoundResponse.cpp -o CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.s

# Object files for target pa2_server
pa2_server_OBJECTS = \
"CMakeFiles/pa2_server.dir/src/main.cpp.o" \
"CMakeFiles/pa2_server.dir/src/server.cpp.o" \
"CMakeFiles/pa2_server.dir/src/worker.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log.cpp.o" \
"CMakeFiles/pa2_server.dir/src/controller.cpp.o" \
"CMakeFiles/pa2_server.dir/src/parser.cpp.o" \
"CMakeFiles/pa2_server.dir/src/request.cpp.o" \
"CMakeFiles/pa2_server.dir/src/response.cpp.o" \
"CMakeFiles/pa2_server.dir/src/responseLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/requestLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/errorLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/execResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o"

# External object files for target pa2_server
pa2_server_EXTERNAL_OBJECTS =

pa2_server: CMakeFiles/pa2_server.dir/src/main.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/server.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/worker.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/controller.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/parser.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/request.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/response.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/responseLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/requestLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/shutdownLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/errorLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/consoleLogger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/fileLogger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/fileResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/dirResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/execResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/notFoundResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/build.make
pa2_server: CMakeFiles/pa2_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable pa2_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa2_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa2_server.dir/build: pa2_server

.PHONY : CMakeFiles/pa2_server.dir/build

CMakeFiles/pa2_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa2_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa2_server.dir/clean

CMakeFiles/pa2_server.dir/depend:
	cd /home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petrsejvl/Dropbox/pa2/server2/pa2_server /home/petrsejvl/Dropbox/pa2/server2/pa2_server /home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug /home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug /home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles/pa2_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa2_server.dir/depend

