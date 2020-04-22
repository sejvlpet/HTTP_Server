cmake_minimum_required(VERSION 3.15)
project(pa2_server)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(pa2_server main.cpp helper.cpp helper.h server.cpp server.h worker.cpp worker.h logger.cpp logger.h log.cpp log.h controller.cpp controller.h parser.cpp parser.h request.cpp request.h)