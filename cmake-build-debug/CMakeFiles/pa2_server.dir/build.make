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

CMakeFiles/pa2_server.dir/main.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa2_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/main.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/main.cpp

CMakeFiles/pa2_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/main.cpp > CMakeFiles/pa2_server.dir/main.cpp.i

CMakeFiles/pa2_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/main.cpp -o CMakeFiles/pa2_server.dir/main.cpp.s

CMakeFiles/pa2_server.dir/src/logic/server.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logic/server.cpp.o: ../src/logic/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa2_server.dir/src/logic/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logic/server.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/server.cpp

CMakeFiles/pa2_server.dir/src/logic/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logic/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/server.cpp > CMakeFiles/pa2_server.dir/src/logic/server.cpp.i

CMakeFiles/pa2_server.dir/src/logic/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logic/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/server.cpp -o CMakeFiles/pa2_server.dir/src/logic/server.cpp.s

CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o: ../src/logic/worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/worker.cpp

CMakeFiles/pa2_server.dir/src/logic/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logic/worker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/worker.cpp > CMakeFiles/pa2_server.dir/src/logic/worker.cpp.i

CMakeFiles/pa2_server.dir/src/logic/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logic/worker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/worker.cpp -o CMakeFiles/pa2_server.dir/src/logic/worker.cpp.s

CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o: ../src/logger/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/logger.cpp

CMakeFiles/pa2_server.dir/src/logger/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logger/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/logger.cpp > CMakeFiles/pa2_server.dir/src/logger/logger.cpp.i

CMakeFiles/pa2_server.dir/src/logger/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logger/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/logger.cpp -o CMakeFiles/pa2_server.dir/src/logger/logger.cpp.s

CMakeFiles/pa2_server.dir/src/log/log.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log/log.cpp.o: ../src/log/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pa2_server.dir/src/log/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log/log.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/log.cpp

CMakeFiles/pa2_server.dir/src/log/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/log.cpp > CMakeFiles/pa2_server.dir/src/log/log.cpp.i

CMakeFiles/pa2_server.dir/src/log/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/log.cpp -o CMakeFiles/pa2_server.dir/src/log/log.cpp.s

CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o: ../src/logic/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/controller.cpp

CMakeFiles/pa2_server.dir/src/logic/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logic/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/controller.cpp > CMakeFiles/pa2_server.dir/src/logic/controller.cpp.i

CMakeFiles/pa2_server.dir/src/logic/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logic/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logic/controller.cpp -o CMakeFiles/pa2_server.dir/src/logic/controller.cpp.s

CMakeFiles/pa2_server.dir/src/io/parser.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/parser.cpp.o: ../src/io/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pa2_server.dir/src/io/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/parser.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/parser.cpp

CMakeFiles/pa2_server.dir/src/io/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/parser.cpp > CMakeFiles/pa2_server.dir/src/io/parser.cpp.i

CMakeFiles/pa2_server.dir/src/io/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/parser.cpp -o CMakeFiles/pa2_server.dir/src/io/parser.cpp.s

CMakeFiles/pa2_server.dir/src/io/request.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/request.cpp.o: ../src/io/request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pa2_server.dir/src/io/request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/request.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/request.cpp

CMakeFiles/pa2_server.dir/src/io/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/request.cpp > CMakeFiles/pa2_server.dir/src/io/request.cpp.i

CMakeFiles/pa2_server.dir/src/io/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/request.cpp -o CMakeFiles/pa2_server.dir/src/io/request.cpp.s

CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o: ../src/io/response/response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/response.cpp

CMakeFiles/pa2_server.dir/src/io/response/response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/response/response.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/response.cpp > CMakeFiles/pa2_server.dir/src/io/response/response.cpp.i

CMakeFiles/pa2_server.dir/src/io/response/response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/response/response.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/response.cpp -o CMakeFiles/pa2_server.dir/src/io/response/response.cpp.s

CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o: ../src/log/responseLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/responseLog.cpp

CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/responseLog.cpp > CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.i

CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/responseLog.cpp -o CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.s

CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o: ../src/log/requestLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/requestLog.cpp

CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/requestLog.cpp > CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.i

CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/requestLog.cpp -o CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.s

CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o: ../src/log/shutdownLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/shutdownLog.cpp

CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/shutdownLog.cpp > CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.i

CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/shutdownLog.cpp -o CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.s

CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o: ../src/log/errorLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/errorLog.cpp

CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/errorLog.cpp > CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.i

CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/log/errorLog.cpp -o CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.s

CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o: ../src/logger/consoleLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/consoleLogger.cpp

CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/consoleLogger.cpp > CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.i

CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/consoleLogger.cpp -o CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.s

CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o: ../src/logger/fileLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/fileLogger.cpp

CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/fileLogger.cpp > CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.i

CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/logger/fileLogger.cpp -o CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.s

CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o: ../src/io/response/fileResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/fileResponse.cpp

CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/fileResponse.cpp > CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.i

CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/fileResponse.cpp -o CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.s

CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o: ../src/io/response/dirResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/dirResponse.cpp

CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/dirResponse.cpp > CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.i

CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/dirResponse.cpp -o CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.s

CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o: ../src/io/response/execResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/execResponse.cpp

CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/execResponse.cpp > CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.i

CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/execResponse.cpp -o CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.s

CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o: CMakeFiles/pa2_server.dir/flags.make
CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o: ../src/io/response/notFoundResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petrsejvl/Dropbox/pa2/server2/pa2_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o -c /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/notFoundResponse.cpp

CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/notFoundResponse.cpp > CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.i

CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petrsejvl/Dropbox/pa2/server2/pa2_server/src/io/response/notFoundResponse.cpp -o CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.s

# Object files for target pa2_server
pa2_server_OBJECTS = \
"CMakeFiles/pa2_server.dir/main.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logic/server.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log/log.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/parser.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/request.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o" \
"CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o"

# External object files for target pa2_server
pa2_server_EXTERNAL_OBJECTS =

pa2_server: CMakeFiles/pa2_server.dir/main.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logic/server.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logic/worker.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logger/logger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log/log.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logic/controller.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/parser.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/request.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/response/response.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log/responseLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log/requestLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log/shutdownLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/log/errorLog.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logger/consoleLogger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/logger/fileLogger.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/response/fileResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/response/dirResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/response/execResponse.cpp.o
pa2_server: CMakeFiles/pa2_server.dir/src/io/response/notFoundResponse.cpp.o
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

