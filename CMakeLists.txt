cmake_minimum_required(VERSION 3.15)
project(pa2_server)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -Wall -pedantic")


add_executable(pa2_server src/main.cpp src/server.cpp src/server.h src/worker.cpp src/worker.h src/logger.cpp src/logger.h src/log.cpp src/log.h src/controller.cpp src/controller.h src/parser.cpp src/parser.h src/request.cpp src/request.h src/response.cpp src/response.h src/responseLog.cpp src/responseLog.h src/requestLog.cpp src/requestLog.h src/shutdownLog.cpp src/shutdownLog.h src/errorLog.cpp src/errorLog.h src/consoleLogger.cpp src/consoleLogger.h src/fileLogger.cpp src/fileLogger.h src/fileResponse.cpp src/fileResponse.h src/dirResponse.cpp src/dirResponse.h src/execResponse.cpp src/execResponse.h src/notFoundResponse.cpp src/notFoundResponse.h src/threadPool.cpp src/threadPool.h)